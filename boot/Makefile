# ----------------------------------------
# Tools
# ----------------------------------------

NASM 			:= nasm

# ----------------------------------------
# Files
# ----------------------------------------

MBR_ASM 		:= mbr.asm
MBR_BIN 		:= mbr.bin

LOADER_ASM 		:= loader.asm
LOADER_BIN 		:= loader.bin

BOOT_BIN		:= boot.bin

# ----------------------------------------
# Rules
# ----------------------------------------

all: $(BOOT_BIN)

$(MBR_BIN): $(MBR_ASM)
	$(NASM) -f bin 				$< -o $@

$(LOADER_BIN): $(LOADER_ASM)
	$(NASM) -f bin 				$< -o $@

$(BOOT_BIN): $(MBR_BIN) $(LOADER_BIN)
	cat $(MBR_BIN) $(LOADER_BIN) > $(BOOT_BIN)

clean:
	rm 	-f 	$(MBR_BIN) $(LOADER_BIN) $(BOOT_BIN)

.PHONY: all clean
