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
FINAL_BIN			:= $(SRC_KERNEL)/final.bin

IMG 				:= keshmiri.img

# ----------------------------------------
# Rules
# ----------------------------------------

all: $(IMG)

$(BOOT_BIN):
	$(MAKE) -C $(SRC_BOOT)

$(FINAL_BIN):
	$(MAKE) -C $(SRC_KERNEL)

$(IMG): $(BOOT_BIN) $(FINAL_BIN)
	$(DD) if=/dev/zero 		of=$(IMG) bs=512 count=110
	$(DD) if=$(BOOT_BIN) 	of=$(IMG) bs=512 count=6 	conv=notrunc
	$(DD) if=$(FINAL_BIN) 	of=$(IMG) bs=512 count=100 	conv=notrunc seek=6

run:
	$(QEMU) -drive format=raw,file=$(IMG) -display sdl,gl=on

clean:
	$(MAKE) -C $(SRC_BOOT) clean
	$(MAKE) -C $(SRC_KERNEL) clean
	rm -f $(IMG)

.PHONY: all run clean
