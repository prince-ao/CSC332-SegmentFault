#pragma once

#ifndef COMMANDS_H
#define COMMANDS_H

#include "commands/helloWorld.h"

typedef struct command_vec {
    char** commands;
    int command_size;
} command_vec;

#endif
