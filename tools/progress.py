#!/usr/bin/env python3

# Adapted from https://github.com/zeldaret/af/blob/main/tools/progress.py, original license is as follows:
# SPDX-FileCopyrightText: © 2023 ZeldaRET
# SPDX-License-Identifier: MIT

from __future__ import annotations

import argparse
import mapfile_parser
from pathlib import Path


ASMPATH = Path("asm")
NONMATCHINGS = "nonmatchings"


def getProgressFromMapFile(mapFile: mapfile_parser.MapFile, asmPath: Path, nonmatchings: Path, filteredFolders: set[str], pathIndex: int=2) -> tuple[mapfile_parser.ProgressStats, dict[str, mapfile_parser.ProgressStats]]:
    totalStats = mapfile_parser.ProgressStats()
    progressPerFolder: dict[str, mapfile_parser.ProgressStats] = dict()

    for segment in mapFile:
        for file in segment:
            if len(file) == 0:
                continue

            # Libultra would be hard to handle since it's linked from an archive. Since it's fully matched,
            # just mark any libultra files as being decompiled.
            if file.filepath.parts[1].startswith("libultra"):
                # Group all libultra files into the parent segment. Use the archive name to tell whether to put it
                # in boot (libultra_rom_boot.a) or core1 (libultra_rom.a).
                if "_boot.a" in file.filepath.parts[1]:
                    folder = "boot"
                else:
                    folder = "core1"
                originalFilePath = file.filepath.parts[1]
                wholeFileIsUndecomped = False
            else:
                folder = file.filepath.parts[pathIndex]

                if folder in filteredFolders:
                    continue

                originalFilePath = Path(*file.filepath.parts[pathIndex:])
                if originalFilePath.suffix == ".o":
                    originalFilePath = originalFilePath.with_suffix("")

                extensionlessFilePath = originalFilePath
                while extensionlessFilePath.suffix:
                    extensionlessFilePath = extensionlessFilePath.with_suffix("")

                fullAsmFile = asmPath / extensionlessFilePath.with_suffix(".s")
                wholeFileIsUndecomped = fullAsmFile.exists()

            if folder not in progressPerFolder:
                progressPerFolder[folder] = mapfile_parser.ProgressStats()


            for func in file:
                funcAsmPath = nonmatchings / extensionlessFilePath / f"{func.name}.s"

                symSize = 0
                if func.size is not None:
                    symSize = func.size

                if wholeFileIsUndecomped:
                    decomped = False
                    totalStats.undecompedSize += symSize
                    progressPerFolder[folder].undecompedSize += symSize
                elif funcAsmPath.exists():
                    decomped = False
                    totalStats.undecompedSize += symSize
                    progressPerFolder[folder].undecompedSize += symSize
                else:
                    decomped = True
                    totalStats.decompedSize += symSize
                    progressPerFolder[folder].decompedSize += symSize

    return totalStats, progressPerFolder


def getProgress(mapPath: Path, version: str) -> tuple[mapfile_parser.ProgressStats, dict[str, mapfile_parser.ProgressStats]]:
    mapFile = mapfile_parser.MapFile()
    mapFile.readMapFile(mapPath)

    for segment in mapFile:
        for file in segment:
            if len(file) == 0:
                continue

            filepathParts = list(file.filepath.parts)
            if version in filepathParts:
                filepathParts.remove(version)
            file.filepath = Path(*filepathParts)

    nonMatchingsPath = ASMPATH / NONMATCHINGS

    return getProgressFromMapFile(mapFile.filterBySectionType(".text"), ASMPATH / version, nonMatchingsPath, {"data"})

def progressMain():
    parser = argparse.ArgumentParser()
    parser.add_argument("-v", "--version", help="version to process", default="us")

    args = parser.parse_args()

    mapPath = Path("build") / args.version / "banjotooie_decompressed.map"

    codeTotalStats, codeProgressPerFolder = getProgress(mapPath, args.version)
    
    mapfile_parser.progress_stats.printStats(codeTotalStats, codeProgressPerFolder)

if __name__ == "__main__":
    progressMain()
