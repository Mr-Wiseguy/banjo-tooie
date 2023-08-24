BUILD_ROOT           := build/us.v10
LD_SCRIPT            := banjotooie.ld
SPLAT_YAML           := baserom.us.v10.yaml
ELF                  := $(BUILD_ROOT)/banjotooie_decompressed.elf
UNCOMPRESSED_ROM     := $(ELF:.elf=.z64)
DECOMPRESSED_BASEROM := decompressed.us.v10.z64
BASEROM              := baserom.us.v10.z64
TEMPROM              := temp.us.v10.z64

SRC_ROOT     := src
ASM_ROOT     := asm
ASSETS_ROOT  := assets
NONMATCHINGS := nonmatchings

C_SRCS     := $(shell find $(SRC_ROOT) -type f -iname '*.c' 2> /dev/null)
S_SRCS     := $(shell find $(ASM_ROOT) -type f -iname "*.s" -not -path "asm/$(NONMATCHINGS)/*" 2> /dev/null)
BIN_SRCS   := $(shell find $(ASSETS_ROOT) -type f -iname '*.bin' 2> /dev/null)

C_OBJS         := $(addprefix $(BUILD_ROOT)/,$(C_SRCS:.c=.c.o))
C_BUILD_DIRS   := $(sort $(dir $(C_OBJS)))
S_OBJS         := $(addprefix $(BUILD_ROOT)/,$(S_SRCS:.s=.s.o))
S_BUILD_DIRS   := $(sort $(dir $(S_OBJS)))
BIN_OBJS       := $(addprefix $(BUILD_ROOT)/,$(BIN_SRCS:.bin=.bin.o))
BIN_BUILD_DIRS := $(sort $(dir $(BIN_OBJS)))

ASM_PROC_C_SRCS := $(shell grep -rl GLOBAL_ASM $(SRC_ROOT) </dev/null)
ASM_PROC_C_OBJS := $(addprefix $(BUILD_ROOT)/,$(ASM_PROC_C_SRCS:.c=.c.o))
ASM_PROC_C_DEPS := $(addprefix $(BUILD_ROOT)/,$(ASM_PROC_C_SRCS:.c=.asmproc.d))
PURE_C_OBJS     := $(filter-out $(ASM_PROC_C_OBJS),$(C_OBJS))

ALL_OBJS     := $(C_OBJS) $(S_OBJS) $(BIN_OBJS)
BUILD_DIRS   := $(C_BUILD_DIRS) $(S_BUILD_DIRS) $(BIN_BUILD_DIRS)

CC       := tools/ido/cc
AS       := mips-linux-gnu-gcc
OBJCOPY  := mips-linux-gnu-objcopy
LD       := mips-linux-gnu-gcc
ASM_PROC := python3 tools/asm-processor/asm_processor.py

OPT_LEVEL := -O2
CFLAGS    := -c -Wab,-r4300_mul -non_shared -G 0 -Xcpluscomm $(OPT_LEVEL) -mips2
CPPFLAGS  := -I include -D_FINALROM -DF3DEX_GBI_2
ASFLAGS   := -march=vr4300 -mabi=32 -mgp32 -mfp32 -mips3 -mno-abicalls -G0 -fno-pic -gdwarf -c -x assembler-with-cpp -D_LANGUAGE_ASSEMBLY
LDFLAGS   := -march=vr4300 -mabi=32 -mgp32 -mfp32 -mips3 -mno-abicalls -G0 -fno-pic -gdwarf -nostartfiles -nostdlib -Wl,-T,$(LD_SCRIPT) -Wl,-T,undefined_syms.us.v10.txt -Wl,-T,undefined_syms_auto.us.v10.txt -Wl,-T,undefined_funcs_auto.us.v10.txt -Wl,--build-id=none -Wl,--emit-relocs
BINOFLAGS := -I binary -O elf32-tradbigmips
Z64OFLAGS := -O binary --gap-fill=0x00

check: $(UNCOMPRESSED_ROM)
	@diff $(DECOMPRESSED_BASEROM) $(UNCOMPRESSED_ROM) && printf "OK\n"

$(UNCOMPRESSED_ROM): $(ELF)
	$(OBJCOPY) $(Z64OFLAGS) $< $@

$(ELF): $(ALL_OBJS) $(LD_SCRIPT)
	$(LD) $(LDFLAGS) -Wl,-Map,$(@:.elf=.map) -o $@

$(ASM_PROC_C_OBJS): $(BUILD_ROOT)/%.c.o: %.c | $(C_BUILD_DIRS)
	$(ASM_PROC) $(OPT_LEVEL) $< > $(BUILD_ROOT)/$<
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $(BUILD_ROOT)/$< -o $@
	$(ASM_PROC) $(OPT_LEVEL) $< --post-process $@ --assembler "$(AS) $(ASFLAGS) $(CPPFLAGS)" --asm-prelude include/prelude.inc

$(PURE_C_OBJS): $(BUILD_ROOT)/%.c.o: %.c | $(C_BUILD_DIRS)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(S_OBJS): $(BUILD_ROOT)/%.s.o: %.s | $(S_BUILD_DIRS)
	$(AS) $(ASFLAGS) $(CPPFLAGS) -c $< -o $@

$(BIN_OBJS): $(BUILD_ROOT)/%.bin.o: %.bin | $(BIN_BUILD_DIRS)
	$(OBJCOPY) $(BINOFLAGS) $< $@

$(BUILD_DIRS):
	mkdir -p $@

clean:
	find $(BUILD_ROOT) -type f -not -name '*.asmproc.d' -delete

setup:
	make -C tools
	cargo run --manifest-path tools/bk_rom_compressor/Cargo.toml --bin bk_rom_decompress $(BASEROM) $(TEMPROM)
	tools/overlay_decompressor baserom.us.v10.z64 temp.us.v10.z64 decompressed.us.v10.z64 > /dev/null
	tools/splat/split.py $(SPLAT_YAML)

distclean:
	rm -rf $(BUILD_ROOT) asm assets $(TEMPROM) $(DECOMPRESSED_BASEROM) undefined_*_auto.us.v10.txt $(LD_SCRIPT)
	make -C tools distclean
	cargo clean --manifest-path tools/bk_rom_compressor/Cargo.toml

-include $(ASM_PROC_C_DEPS)

# Disable implicit rules
MAKEFLAGS += -r

# Disable built-in rules
.SUFFIXES:

# Phony targets
.PHONY: clean check setup distclean

# Debug variable print target
print-% : ; $(info $* is a $(flavor $*) variable set to [$($*)]) @true
