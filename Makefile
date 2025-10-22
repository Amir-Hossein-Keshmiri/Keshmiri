NASM := nasm
DD := dd
QEMU := qemu-system-x86_64

MBR_ASM := boot/mbr.asm
MBR_BIN := boot/mbr.bin

LOADER_ASM := boot/loader.asm
LOADER_BIN := boot/loader.bin

IMG := keshmiri.img

all: $(IMG)

$(MBR_BIN): $(MBR_ASM)
	$(NASM) -f bin $(MBR_ASM) -o $(MBR_BIN)

$(LOADER_BIN): $(LOADER_ASM)
	$(NASM) -f bin $(LOADER_ASM) -o $(LOADER_BIN)

$(IMG): $(MBR_BIN) $(LOADER_BIN)
	$(DD) if=/dev/zero of=$(IMG) bs=512 count=110
	$(DD) if=$(MBR_BIN) of=$(IMG) bs=512 count=1 conv=notrunc
	$(DD) if=$(LOADER_BIN) of=$(IMG) bs=512 count=5 seek=1 conv=notrunc

run:
	$(QEMU) -hda $(IMG)

clean:
	rm -f $(MBR_BIN)
	rm -f $(LOADER_BIN)
	rm -f $(IMG)

.PHONY: all run clean
