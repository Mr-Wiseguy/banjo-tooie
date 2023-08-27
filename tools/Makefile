# IDO
IDO_DIR   := ido
IDO       := $(IDO_DIR)/cc

all: overlay_decompressor overlay_processor $(IDO)

overlay_decompressor: overlay_decompressor.cpp
	g++ -std=c++20 -O2 $^ -o $@ -Wall -Wextra -Wpedantic -lz -lfmt

overlay_processor: overlay_processor.cpp
	g++ -std=c++20 -O2 $^ -o $@ -Wall -Wextra -Wpedantic -lz -lfmt -Ielfio

$(IDO): | $(IDO_DIR)
	wget https://github.com/decompals/ido-static-recomp/releases/latest/download/ido-5.3-recomp-ubuntu-20.04.tar.gz
	tar xf ido-5.3-recomp-ubuntu-20.04.tar.gz -C $(IDO_DIR)
	$(RM) ido-5.3-recomp-ubuntu-20.04.tar.gz

$(IDO_DIR):
	mkdir $@

distclean:
	rm -rf $(IDO_DIR) overlay_decompressor overlay_processor

.PHONY: distclean
