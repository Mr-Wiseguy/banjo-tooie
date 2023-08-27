#!/usr/bin/env python3
import toml
import sys

if len(sys.argv) != 2:
    print(f"Usage: {sys.argv[0]} [overlay toml]")
    exit(0)

config = toml.load(sys.argv[1])

for overlay in config["overlay"]:
    if not overlay.get("empty", False):
        print(overlay["name"])
