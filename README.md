# Banjo Tooie Decomp

## Setup

* Clone this repo recursively with git.
  * If you've already cloned, then init submodules recursively instead.
* Install packages for the C++ libraries fmtlib and toml11.
  * Ubuntu: `sudo apt install libfmt-dev libtoml11-dev`
* Install pip requirements for splat.
  * `python3 -m pip install -r tools/splat/requirements.txt`
* Install pip requirements for this project.
  * `python3 -m pip install -r tools/requirements.txt`
* Place a copy of Banjo Tooie NTSC-U in this folder and name it `baserom.us.z64`.
* Run `make setup` to decompress the rom and split it.
* Run `make` (with an optional job count) to build the rom.
