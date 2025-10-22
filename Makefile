# ----------------------------------------
# Tools
# ----------------------------------------

NASM 				:= nasm
LD					:= ld
OBJCOPY				:= objcopy
GCC					:= gcc
DD 					:= dd
QEMU 				:= qemu-system-x86_64

# ----------------------------------------
# Flags
# ----------------------------------------

LD_FLAGES			:= -Ttext=0x200000
GCC_FLAGES			:= -ffreestanding -nostdlib -m64 -c -Wall

# ----------------------------------------
# Paths
# ----------------------------------------

SRC_BOOT 			:= boot
SRC_KERNEL			:= kernel

# ----------------------------------------
# Files
# ----------------------------------------

MBR_ASM 			:= $(SRC_BOOT)/mbr.asm
MBR_BIN 			:= $(SRC_BOOT)/mbr.bin

LOADER_ASM 			:= $(SRC_BOOT)/loader.asm
LOADER_BIN 			:= $(SRC_BOOT)/loader.bin

KERNEL_ENTRY_ASM 	:= $(SRC_KERNEL)/kernel_entry.asm
KERNEL_ENTRY_O 		:= $(SRC_KERNEL)/kernel_entry.o

KERNEL_C			:= $(SRC_KERNEL)/kernel.c
KERNEL_O			:= $(SRC_KERNEL)/kernel.o

KERNEL_ELF			:= $(SRC_KERNEL)/kernel.elf

KERNEL_BIN			:= $(SRC_KERNEL)/kernel.bin

IMG 				:= keshmiri.img

# ----------------------------------------
# Rules
# ----------------------------------------

all: $(IMG)

$(MBR_BIN): $(MBR_ASM)
	$(NASM) -f bin 				$< -o $@

$(LOADER_BIN): $(LOADER_ASM)
	$(NASM) -f bin 				$< -o $@

$(KERNEL_ENTRY_O): $(KERNEL_ENTRY_ASM)
	$(NASM) -f elf64 			$< -o $@

$(KERNEL_O): $(KERNEL_C)
	$(GCC) 	$(GCC_FLAGES) 	 	$< -o $@

$(KERNEL_ELF): $(KERNEL_ENTRY_O) $(KERNEL_O)
	$(LD) 	$(LD_FLAGES) 		$^ -o $@

$(KERNEL_BIN): $(KERNEL_ELF)
	$(OBJCOPY) 					$< -O binary $@

$(IMG): $(MBR_BIN) $(LOADER_BIN) $(KERNEL_BIN)
	$(DD) if=/dev/zero 		of=$(IMG) bs=512 count=110
	$(DD) if=$(MBR_BIN) 	of=$(IMG) bs=512 count=1 	conv=notrunc
	$(DD) if=$(LOADER_BIN) 	of=$(IMG) bs=512 count=5 	conv=notrunc seek=1
	$(DD) if=$(KERNEL_BIN) 	of=$(IMG) bs=512 count=100 	conv=notrunc seek=6


run:
	$(QEMU) -hda $(IMG)


clean:
	rm 	-f 	$(MBR_BIN)
	rm 	-f 	$(LOADER_BIN)
	rm 	-f 	$(KERNEL_ENTRY_O)
	rm 	-f 	$(KERNEL_O)
	rm 	-f 	$(KERNEL_ELF)
	rm 	-f 	$(KERNEL_BIN)
	rm 	-f 	$(IMG)


.PHONY: all run clean
