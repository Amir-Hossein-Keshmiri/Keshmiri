# ----------------------------------------
# Tools
# ----------------------------------------

GCC					:= gcc
LD					:= ld
NASM 				:= nasm
OBJCOPY				:= objcopy

# ----------------------------------------
# Flags
# ----------------------------------------

LD_FLAGES			:= -Ttext=0x200000
GCC_FLAGES			:= -ffreestanding -nostdlib -m64 -c -Wall

# ----------------------------------------
# Files
# ----------------------------------------


KERNEL_ENTRY_ASM 	:= kernel_entry.asm
KERNEL_ENTRY_O 		:= kernel_entry.o

FINAL_C				:= final.c
FINAL_O				:= final.o

FINAL_ELF			:= final.elf

FINAL_BIN			:= final.bin

# ----------------------------------------
# Rules
# ----------------------------------------

all: $(FINAL_BIN)

$(KERNEL_ENTRY_O): $(KERNEL_ENTRY_ASM)
	$(NASM) -f elf64 			$< -o $@

$(FINALEL_O): $(KERNEL_C)
	$(GCC) 	$(GCC_FLAGES) 	 	$< -o $@

$(FINAL_ELF): $(KERNEL_ENTRY_O) $(FINAL_O)
	$(LD) 	$(LD_FLAGES) 		$^ -o $@

$(FINAL_BIN): $(FINAL_ELF)
	$(OBJCOPY) 					$< -O binary $@

clean:
	rm 	-f 	$(KERNEL_ENTRY_O) $(FINAL_O) $(FINAL_ELF) $(FINAL_BIN)

.PHONY: all clean
