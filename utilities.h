#pragma once

#ifndef UTILITIES_H
#define UTILITIES_H

#include "includes.h"
#define MAX_COMMANDS 5

void append_command(char **, char *, int *);
int generateIndex(char *);
void throwError(char *);

#endif
