# Banjo Tooie Decomp

![code Progress]
![boot Progress]
![core1 Progress]
![core2 Progress]
![overlays Progress]

[code Progress]: https://img.shields.io/endpoint?label=All&url=https%3A%2F%2Fprogress.deco.mp%2Fdata%2Ftooie%2Fus%2Fcode%2F%3Fmode%3Dshield%26measure%3Dall
[boot Progress]: https://img.shields.io/endpoint?label=Boot&url=https%3A%2F%2Fprogress.deco.mp%2Fdata%2Ftooie%2Fus%2Fcode%2F%3Fmode%3Dshield%26measure%3Dboot
[core1 Progress]: https://img.shields.io/endpoint?label=Core1&url=https%3A%2F%2Fprogress.deco.mp%2Fdata%2Ftooie%2Fus%2Fcode%2F%3Fmode%3Dshield%26measure%3Dcore1
[core2 Progress]: https://img.shields.io/endpoint?label=Core2&url=https%3A%2F%2Fprogress.deco.mp%2Fdata%2Ftooie%2Fus%2Fcode%2F%3Fmode%3Dshield%26measure%3Dcore2
[overlays Progress]: https://img.shields.io/endpoint?label=Overlays&url=https%3A%2F%2Fprogress.deco.mp%2Fdata%2Ftooie%2Fus%2Fcode%2F%3Fmode%3Dshield%26measure%3Doverlays

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
