#!/usr/bin/env python3

from glob import glob
from pathlib import Path
import os
import yaml
import subprocess

# Any prefix listed here should, if found, be moved into the respective subdirectory(ies)
PREFIX_MAP = {
    "baegg": "ba/egg",
    "bamove": "ba/move",
    "bsban": "bs/ban",
    "bsdrone": "bs/drone",
    "bskaz": "bs/kaz",
    "bsmum": "bs/mum",
    "changlerboss": "ch/anglerboss",
    "chbad": "ch/bad",
    "chboggy": "ch/boggy",
    "chboiler": "ch/boiler",
    "chbottles": "ch/bottles",
    "chdigger": "ch/digger",
    "chdino": "ch/dino",
    "chegg": "ch/egg",
    "chfactory": "ch/factory",
    "chfair": "ch/fair",
    "chfantasy": "ch/fantasy",
    "chfire": "ch/fire",
    "chgobi": "ch/gobi",
    "chgold": "ch/gold",
    "chgrunty": "ch/grunty",
    "chhot": "ch/hot",
    "chintro": "ch/intro",
    "chjiggy": "ch/jiggy",
    "chjigsaw": "ch/jigsaw",
    "chklungo": "ch/klungo",
    "chlagoon": "ch/lagoon",
    "chlava": "ch/lava",
    "chlight": "ch/light",
    "chmine": "ch/mine",
    "chmole": "ch/mole",
    "chmumbo": "ch/mumbo",
    "chstarspinner": "ch/starspinner",
    "chtemple": "ch/temple",
    "chtnt": "ch/tnt",
    "chwaterfall": "ch/waterfall",
    "chweldarboss": "ch/weldarboss",
    "chwitchy": "ch/witchy",
    "gcdialog": "gc/dialog",
    "gcmapsects": "gc/mapsects",
    "glspline": "gl/spline",
    "ncba": "nc/ba",
    "ncpod": "nc/pod",
    "seq": "seq",
    "subaddie": "su/baddie",
    "sucoaster": "su/coaster",
}

IGNORED_FILES = (
    "markersDll.c",
    "seq.c"
)

PROJECT_ROOT = os.path.normpath(os.path.join(os.path.dirname(__file__), os.path.pardir))
OVERLAYS_PATH = os.path.join(PROJECT_ROOT, "src", "overlays")
SPLAT_CONFIG = os.path.join(PROJECT_ROOT, "baserom.us.yaml")

DRY_RUN = True

def main():
    files = glob(f"{OVERLAYS_PATH}/**/*.c")
    config_yaml = None
    config_str = ""
    with open(SPLAT_CONFIG, "r") as c:
        try:
            config_str = c.read()
            config_yaml = yaml.safe_load(config_str)
        except yaml.YAMLError as exc:
            print(f"Could not load {SPLAT_CONFIG}: {exc}")

    if config_yaml is None:
        print(f"Failed to load splat config. Stopping")
        exit(1)

    if "segments" not in config_yaml:
        print("Could not find segments in config. Stopping")
        exit(1)

    # list of segments, we mainly care about the dir and subsegments property
    segments = config_yaml["segments"]  # type: ignore

    for file in files:
        file_name = os.path.basename(file)

        if file_name in IGNORED_FILES:
            print(f"Skipping file {file}")
            continue

        source_name = file_name.replace(".c", "")
        source_file_name = os.path.join(OVERLAYS_PATH, source_name, file_name)
        target_file_name = determine_target_file_name(file_name)
        target_directory = os.path.dirname(target_file_name)

        # move file and delete original directory
        print(f"Moving {source_file_name} to {target_file_name}.")
        if DRY_RUN is False:
            Path(os.path.join(OVERLAYS_PATH, target_directory)).mkdir(
                parents=True, exist_ok=True
            )
            subprocess.run(['git', 'mv', source_file_name, target_file_name])

        source_directory = os.path.dirname(source_file_name)

        print(f"Removing {source_directory}")
        if DRY_RUN is False:
            os.removedirs(source_directory)

        # rename file in splat config
        for segment in segments:
            if "name" not in segment:
                continue
            if segment["name"] != source_name:
                continue

            target_config_dir = target_directory.replace(
                os.path.join(PROJECT_ROOT, "src", ""), ""
            )

            print(
                f"Renaming dir {segment["dir"]} to {target_config_dir} in config segment"
            )
            if DRY_RUN is False:
                # The "     type: code" is required as we do not want to modify the directory of the header"
                config_str = config_str.replace(
                    f"dir: {segment["dir"]}\n    type: code",
                    f"dir: {target_config_dir}\n    type: code",
                )

            if "subsegments" not in segment:
                # No subsegments so nothing to rename here
                continue

            target_name = os.path.basename(target_file_name).replace(".c", "")
            for subsegment in segment["subsegments"]:
                # first item is address, second is type, third is name
                print(
                    f"Renaming {subsegment[2]} to {target_name} for {subsegment[1]} as address 0x{subsegment[0]}"
                )
                if DRY_RUN is False:
                    config_str = config_str.replace(
                        f", {subsegment[2]}]",
                        f", {target_name}]",
                    )
            break  # stop the segments loop as there should only be one segment for the current file

    if DRY_RUN is False:
        with open(SPLAT_CONFIG, "w") as c:
            c.write(config_str)


def determine_target_file_name(file_name: str) -> str:
    for prefix in PREFIX_MAP:
        if file_name == f"{prefix}.c":
            # Skip if the file name is the prefix, e.g. skip bsdrone.c if prefix is bsdrone
            continue

        if file_name.startswith(prefix) is False:
            continue

        # File is in prefix map, set target file name to use predetermined directory
        return os.path.join(
            OVERLAYS_PATH, PREFIX_MAP[prefix], file_name.replace(prefix, "")
        )

    # File had no prefix map entry, take first two letters as parent directory
    return os.path.join(
        OVERLAYS_PATH, file_name[0:2], file_name.replace(file_name[0:2], "")
    )


if __name__ == "__main__":
    main()
