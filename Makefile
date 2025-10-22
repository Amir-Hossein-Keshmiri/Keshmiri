NASM 		:= nasm
DD 			:= dd
QEMU 		:= qemu-system-x86_64


MBR_ASM 	:= boot/mbr.asm
MBR_BIN 	:= boot/mbr.bin

LOADER_ASM 	:= boot/loader.asm
LOADER_BIN 	:= boot/loader.bin

KERNEL_ASM 	:= kernel/kernel.asm
KERNEL_BIN 	:= kernel/kernel.bin

IMG 		:= keshmiri.img


all: $(IMG)

$(MBR_BIN): $(MBR_ASM)
	$(NASM) -f bin 	$(MBR_ASM) 		-o $(MBR_BIN)

$(LOADER_BIN): $(LOADER_ASM)
	$(NASM) -f bin 	$(LOADER_ASM)	-o $(LOADER_BIN)

$(KERNEL_BIN): $(KERNEL_ASM)
	$(NASM) -f bin 	$(KERNEL_ASM) 	-o $(KERNEL_BIN)

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
	rm 	-f 	$(KERNEL_BIN)
	rm 	-f 	$(IMG)


.PHONY: all run clean
