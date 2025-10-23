# ----------------------------------------
# Tools
# ----------------------------------------

DD 					:= dd
QEMU 				:= qemu-system-x86_64

# ----------------------------------------
# Paths
# ----------------------------------------

SRC_BOOT 			:= boot
SRC_KERNEL			:= kernel

# ----------------------------------------
# Files
# ----------------------------------------

BOOT_BIN			:= $(SRC_BOOT)/boot.bin
KERNEL_BIN			:= $(SRC_KERNEL)/kernel.bin

IMG 				:= keshmiri.img

# ----------------------------------------
# Rules
# ----------------------------------------

all: $(IMG)

$(BOOT_BIN):
	$(MAKE) -C $(SRC_BOOT)

$(KERNEL_BIN):
	$(MAKE) -C $(SRC_KERNEL)

$(IMG): $(BOOT_BIN) $(KERNEL_BIN)
	$(DD) if=/dev/zero 		of=$(IMG) bs=512 count=110
	$(DD) if=$(BOOT_BIN) 	of=$(IMG) bs=512 count=6 	conv=notrunc
	$(DD) if=$(KERNEL_BIN) 	of=$(IMG) bs=512 count=100 	conv=notrunc seek=6

run:
	$(QEMU) -hda $(IMG)

clean:
	$(MAKE) -C $(SRC_BOOT) clean
	$(MAKE) -C $(SRC_KERNEL) clean
	rm -f $(IMG)

.PHONY: all run clean
