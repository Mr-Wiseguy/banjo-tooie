# IDO
IDO_DIR   := ido
IDO       := $(IDO_DIR)/cc
RAREZIP_DIR := rarezip/gzip
RAREZIP     := $(RAREZIP_DIR)/librarezip.a

UTILS_SRC := tooie_utils.cpp
UTILS_H   := $(UTILS_SRC:.cpp=.h)
UTILS_OBJ := $(UTILS_SRC:.cpp=.o)

PROGRAMS := rom_decompressor syscall_builder overlay_processor rom_compressor n64crc

all: $(PROGRAMS) $(IDO)

rom_decompressor: rom_decompressor.cpp $(UTILS_OBJ) $(UTILS_H)
	g++ -std=c++20 -O2 $< $(UTILS_OBJ) -o $@ -Wall -Wextra -Wpedantic -lz -lfmt

overlay_processor: overlay_processor.cpp $(UTILS_OBJ) $(UTILS_H)
	g++ -std=c++20 -O2 $< $(UTILS_OBJ) -o $@ -Wall -Wextra -Wpedantic -lz -lfmt

rom_compressor: rom_compressor.cpp $(UTILS_OBJ) $(RAREZIP) $(UTILS_H)
	g++ -std=c++20 -O2 $< $(UTILS_OBJ) $(RAREZIP) -o $@ -Wall -Wextra -Wpedantic -I$(RAREZIP_DIR) -lfmt

syscall_builder: syscall_builder.cpp $(UTILS_OBJ) $(UTILS_H)
	g++ -std=c++20 -O2 $< $(UTILS_OBJ) -o $@ -Wall -Wextra -Wpedantic -lfmt

$(UTILS_OBJ) : $(UTILS_SRC) $(UTILS_H)
	g++ -std=c++20 -O2 $< -o $@ -c -Wall -Wextra -Wpedantic -Ielfio

n64crc: n64crc.c
	gcc -O2 $^ -o $@ -Wall -Wextra -Wpedantic

$(IDO): | $(IDO_DIR)
	wget https://github.com/decompals/ido-static-recomp/releases/latest/download/ido-5.3-recomp-ubuntu-20.04.tar.gz
	tar xf ido-5.3-recomp-ubuntu-20.04.tar.gz -C $(IDO_DIR)
	$(RM) ido-5.3-recomp-ubuntu-20.04.tar.gz

$(IDO_DIR):
	mkdir $@

$(RAREZIP):
	make -C $(RAREZIP_DIR)

clean:
	rm -rf $(PROGRAMS) $(UTILS_OBJ)

distclean:
	rm -rf $(IDO_DIR) $(PROGRAMS) $(UTILS_OBJ)

.PHONY: all clean distclean
