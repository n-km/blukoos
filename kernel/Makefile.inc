C_SOURCES += kernel/kernel.c

include kernel/console/Makefile.inc
include kernel/drivers/video/Makefile.inc
include kernel/drivers/input/Makefile.inc
include kernel/arch/x86/Makefile.inc