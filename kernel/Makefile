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

KERNEL_C			:= kernel.c
KERNEL_O			:= kernel.o

KERNEL_ELF			:= kernel.elf

KERNEL_BIN			:= kernel.bin

# ----------------------------------------
# Rules
# ----------------------------------------

all: $(KERNEL_BIN)

$(KERNEL_ENTRY_O): $(KERNEL_ENTRY_ASM)
	$(NASM) -f elf64 			$< -o $@

$(KERNEL_O): $(KERNEL_C)
	$(GCC) 	$(GCC_FLAGES) 	 	$< -o $@

$(KERNEL_ELF): $(KERNEL_ENTRY_O) $(KERNEL_O)
	$(LD) 	$(LD_FLAGES) 		$^ -o $@

$(KERNEL_BIN): $(KERNEL_ELF)
	$(OBJCOPY) 					$< -O binary $@

clean:
	rm 	-f 	$(KERNEL_ENTRY_O) $(KERNEL_O) $(KERNEL_ELF) $(KERNEL_BIN)

.PHONY: all clean
