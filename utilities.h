#pragma once

#ifndef UTILITIES_H
#define UTILITIES_H

#include "includes.h"
#include <unistd.h>
#include <time.h>
#include "commands.h"
#include "commands/exit.h"
#define MAX_COMMANDS 5

void append_command(char **, char *, int *);
int generateIndex(char *, command_vec*);
void throwError(char *);

#endif
