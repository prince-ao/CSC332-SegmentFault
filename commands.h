#pragma once

#ifndef COMMANDS_H
#define COMMANDS_H

#include "commands/helloWorld.h"
#include "commands/tree.h"
#include "commands/list.h"
#include "commands/kill.h"

typedef struct command_vec {
    char** commands;
    int command_size;
} command_vec;

#endif
