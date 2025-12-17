CONSOLE_DIR := kernel/console

C_SOURCES += \
  $(CONSOLE_DIR)/console.c \
  $(shell find $(CONSOLE_DIR)/shell -type f -name '*.c') \
  $(shell find $(CONSOLE_DIR)/commands -type f -name '*.c')

CFLAGS += -I$(CONSOLE_DIR) -I$(CONSOLE_DIR)/shell -I$(CONSOLE_DIR)/commands
