MBR_ASM := boot/mbr.asm
MBR_BIN := boot/mbr.bin
IMG := keshmiri.img

all: $(IMG) 

$(MBR_BIN): $(MBR_ASM)
	nasm -f bin $(MBR_ASM) -o $(MBR_BIN)

$(IMG): $(MBR_BIN)
	dd if=$(MBR_BIN) of=$(IMG) bs=512 count=1

run:
	qemu-system-x86_64 -hda $(IMG)

clean:
	rm -f $(MBR_BIN)
	rm -f $(IMG)

.PHONY: all run clean
