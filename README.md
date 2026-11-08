# Banjo Tooie Decomp

| Category  | DecompedSize /    Total | OfFolder%  | OfTotal%|
| ------------- | ------------- | ------------- | ------------- |
| all  | 740244 /  2904832  | 25.4832% | 25.4832% / 100.0000% |
| boot  | 15936 /    15936  | 100.0000% | 0.5486% /   0.5486% |
| core1  | 65192 /   153680  | 42.4206% |2.2443% /   5.2905%|
| core2  | 184936 /   616096  | 30.0174% | 6.3667% /  21.2094% |
| overlays  | 474180 /  2119120  | 22.3763% | 16.3238% /  72.9516% |

## Setup

- Clone this repo recursively with git.
  - If you've already cloned, then init submodules recursively instead.
  - `git submodule update --init --recursive`
- Install packages for the C++ libraries fmtlib and toml11.
  - Ubuntu: `sudo apt install libfmt-dev libtoml11-dev gcc-mips-linux-gnu`
- Install pip requirements for splat.
  - `python3 -m pip install -r tools/splat/requirements.txt`
- Install pip requirements for this project.
  - `python3 -m pip install -r tools/requirements.txt`
- Place a copy of Banjo Tooie NTSC-U (SHA1 = af1a89e12b638b8d82cc4c085c8e01d4cba03fb3) in this folder and name it `baserom.us.z64`.
- Run `make setup` to decompress the rom and split it.
- Run `make` (with an optional job count) to build the rom.
