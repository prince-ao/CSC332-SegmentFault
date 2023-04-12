#include"utilities.h"
#include "commands.h"
#include <unistd.h>

void append_command(char **commands, char *command, int *index){
	if((*index) == MAX_COMMANDS){
		free(commands[0]);
		for(int i = 1; i < MAX_COMMANDS; i++){
			commands[i-1] = commands[i];
		}
		commands[(*index)-1] = command;
	}else{
		commands[(*index)] = command;
		(*index)++;
	}
}

int generateIndex(char *user_input, command_vec* commands){
	for(int i = 0; i < commands->command_size; i++){
		if(!strcmp(user_input, commands->commands[i])){
			return i;
		}
	}
	return -1;
}

void throwError(char *err){
	perror(err);
	exit(1);
}
