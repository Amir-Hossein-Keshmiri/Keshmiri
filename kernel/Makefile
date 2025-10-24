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

LD_FLAGS			:= -Ttext=0x200000
GCC_CFLAGS 			:= -ffreestanding -nostdlib -m64 -fno-stack-protector -fno-pie -no-pie -Wall -c

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

$(FINAL_O): $(FINAL_C)
	$(GCC) 	$(GCC_CFLAGS) 	 	$< -o $@

$(FINAL_ELF): $(KERNEL_ENTRY_O) $(FINAL_O)
	$(LD) 	$(LD_FLAGS) 		$^ -o $@

$(FINAL_BIN): $(FINAL_ELF)
	$(OBJCOPY) 					$< -O binary $@

clean:
	rm 	-f 	$(KERNEL_ENTRY_O) $(FINAL_O) $(FINAL_ELF) $(FINAL_BIN)

.PHONY: all clean
