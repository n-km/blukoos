#pragma once
#include "console/shell/command.h"

#define REGISTER_COMMAND(sym) __attribute__((section(".commands"), used)) const command_t sym