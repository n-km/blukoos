ENTRY(_start)

SECTIONS {
    . = 2M;                     /* Kernel bei 2 MiB laden */

    .text : {
        *(.multiboot)           /* Multiboot-Header zuerst! */
        *(.text)
    }

    .rodata : {
        *(.rodata)
    }

    .data : {
        *(.data)
    }

    .bss : {
        *(COMMON)
        *(.bss)
    }

    .commands : {
        __cmd_start = .;
        KEEP(*(.commands))
        __cmd_end = .;
  }

}