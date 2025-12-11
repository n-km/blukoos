/* Multiboot-Header */
.set ALIGN,    1<<0
.set MEMINFO,  1<<1
.set FLAGS,    ALIGN | MEMINFO
.set MAGIC,    0x1BADB002
.set CHECKSUM, -(MAGIC + FLAGS)

.section .multiboot
.align 4
.long MAGIC
.long FLAGS
.long CHECKSUM

/* Stack-Bereich */
.section .bss
.align 16
stack_bottom:
.skip 16384  # 16 KiB Stack
stack_top:

/* Kernel-Einstiegspunkt */
.section .text
.global _start
_start:
    mov $stack_top, %esp   # Stack setzen
    call kernel_main       # Sprung zum C-Code

    cli                    # Interrupts deaktivieren
1:  hlt
    jmp 1b