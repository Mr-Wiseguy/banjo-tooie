#!/usr/bin/env python3

# Adapted from https://github.com/zeldaret/af/blob/main/tools/upload_frogress.py, original license is as follows:
# SPDX-FileCopyrightText: © 2023 ZeldaRET
# SPDX-License-Identifier: MIT

from __future__ import annotations

import argparse
import mapfile_parser
from pathlib import Path

import progress


BASE_URL = "https://progress.deco.mp"
PROJECT = "tooie"

def uploadProgressMain():
    parser = argparse.ArgumentParser()
    parser.add_argument("version", help="Version slug")
    parser.add_argument("--apikey", help="API key")

    args = parser.parse_args()

    version: str = args.version
    apikey: str = args.apikey
    mapPath = Path("build") / args.version / "banjotooie_decompressed.map"

    codeTotalStats, codeProgressPerFolder = progress.getProgress(mapPath, version)
    codeEntries: dict[str, int] = mapfile_parser.frontends.upload_frogress.getFrogressEntriesFromStats(codeTotalStats, codeProgressPerFolder, verbose=True)

    url = mapfile_parser.utils.generateFrogressEndpointUrl(BASE_URL, PROJECT, version)
    mapfile_parser.frontends.upload_frogress.uploadEntriesToFrogress(codeEntries, "code", url, apikey=apikey, verbose=True)

if __name__ == '__main__':
    uploadProgressMain()
