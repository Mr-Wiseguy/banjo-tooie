# IDO
IDO_DIR   := ido
IDO       := $(IDO_DIR)/cc
RAREZIP_DIR := rarezip/gzip
RAREZIP     := $(RAREZIP_DIR)/librarezip.a
TOML_DIR      := toml11
TOML_INC_DIR  := $(TOML_DIR)/include
FMT_DIR       := fmt
FMT_INC_DIR   := $(FMT_DIR)/include
ELFIO_DIR     := elfio
ELFIO_INC_DIR := $(ELFIO_DIR)


UTILS_SRC := tooie_utils.cpp
UTILS_H   := $(UTILS_SRC:.cpp=.h)
UTILS_OBJ := $(UTILS_SRC:.cpp=.o)
UTILS_INC := -I $(TOML_INC_DIR) -I $(FMT_INC_DIR) -I $(ELFIO_INC_DIR)

FMT_SRC := $(FMT_DIR)/src/format.cc
FMT_OBJ := $(notdir $(FMT_SRC:.cc=.o))

PROGRAMS := rom_decompressor syscall_builder overlay_processor rom_compressor n64crc

all: $(PROGRAMS) $(IDO)

rom_decompressor: rom_decompressor.cpp $(UTILS_OBJ) $(FMT_OBJ) $(UTILS_H)
	g++ -std=c++20 -O2 $< $(UTILS_OBJ) $(FMT_OBJ) -I $(FMT_INC_DIR) -o $@ -Wall -Wextra -Wpedantic -lz -lfmt

overlay_processor: overlay_processor.cpp $(UTILS_OBJ) $(FMT_OBJ) $(UTILS_H)
	g++ -std=c++20 -O2 $< $(UTILS_OBJ) $(FMT_OBJ) -I $(FMT_INC_DIR) -o $@ -Wall -Wextra -Wpedantic -lz -lfmt

rom_compressor: rom_compressor.cpp $(UTILS_OBJ) $(FMT_OBJ) $(RAREZIP) $(UTILS_H)
	g++ -std=c++20 -O2 $< $(UTILS_OBJ) $(FMT_OBJ) -I $(FMT_INC_DIR) $(RAREZIP) -o $@ -Wall -Wextra -Wpedantic -I$(RAREZIP_DIR) -lfmt

syscall_builder: syscall_builder.cpp $(UTILS_OBJ) $(FMT_OBJ) $(UTILS_H)
	g++ -std=c++20 -O2 $< $(UTILS_OBJ) $(FMT_OBJ) -I $(FMT_INC_DIR) -o $@ -Wall -Wextra -Wpedantic -lfmt

$(UTILS_OBJ) : $(UTILS_SRC) $(UTILS_H)
	g++ -std=c++20 -O2 $< -o $@ $(UTILS_INC) -c -Wall -Wextra -Wpedantic

$(FMT_OBJ) : $(FMT_SRC)
	g++ -std=c++20 -O2 $< -o $@ -I $(FMT_INC_DIR) -c -Wall -Wextra -Wpedantic

n64crc: n64crc.c
	gcc -O2 $^ -o $@ -Wall -Wextra -Wpedantic

$(IDO): | $(IDO_DIR)
	wget https://github.com/decompals/ido-static-recomp/releases/download/v1.1/ido-5.3-recomp-linux.tar.gz
	tar xf ido-5.3-recomp-linux.tar.gz -C $(IDO_DIR)
	$(RM) ido-5.3-recomp-linux.tar.gz

$(IDO_DIR):
	mkdir $@

$(RAREZIP):
	make -C $(RAREZIP_DIR)

clean:
	rm -rf $(PROGRAMS) $(UTILS_OBJ) $(FMT_OBJ)

distclean:
	rm -rf $(IDO_DIR) $(PROGRAMS) $(UTILS_OBJ) $(FMT_OBJ)

.PHONY: all clean distclean
