MAKEFLAGS += --warn-undefined-variables

TARGET  = blukoos
ISO     = $(TARGET).iso

CC      = gcc
AS      = gcc
LD      = ld

CFLAGS  = -m32 -ffreestanding -O2 -Wall -Wextra -Ikernel
LDFLAGS = -m elf_i386 -T kernel/linker.ld -nostdlib

C_SOURCES :=
ASM_SOURCES := kernel/arch/x86/boot.s

include kernel/Makefile.inc

C_OBJS   = $(C_SOURCES:.c=.o)
ASM_OBJS = $(ASM_SOURCES:.s=.o)
OBJS     = $(C_OBJS) $(ASM_OBJS)

all: $(ISO)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.s
	$(AS) -m32 -c $< -o $@

kernel.bin: $(OBJS)
	$(LD) $(LDFLAGS) -o $@ $(OBJS)

iso/boot/grub/grub.cfg:
	mkdir -p iso/boot/grub
	printf 'set timeout=0\nset default=0\nmenuentry "blukoos" {\n  multiboot /boot/kernel.bin\n  boot\n}\n' > iso/boot/grub/grub.cfg

$(ISO): kernel.bin iso/boot/grub/grub.cfg
	cp kernel.bin iso/boot/kernel.bin
	grub-mkrescue -o $(ISO) iso

run: $(ISO)
	qemu-system-i386 -cdrom $(ISO)

clean:
	rm -rf $(OBJS) kernel.bin iso $(ISO)