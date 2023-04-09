#include"utilities.h"
#include"commands.h"

int main(void){
	char **prev_commands = (char **)malloc(MAX_COMMANDS * sizeof(char*));
	int prev_commands_index;
	char *user_input;
	char temp_buffer;
	int buffer_size;
	char *prompt = "> ";
	char *cmdnf = "Command Not Found\n";

	while(1){
		write(STDOUT_FILENO, prompt, strlen(prompt));
		int buffer_counter = 0;
		int current_size = 5;
		user_input = (char *)malloc(current_size * sizeof(char));
		while((buffer_size = read(STDIN_FILENO, &temp_buffer, 1)) > 0){
			if(buffer_counter == current_size){
				current_size *= 2;
				user_input = (char *)realloc(user_input, current_size);
			}
			user_input[buffer_counter] = temp_buffer;

			if(temp_buffer == '\n') {
				user_input = (char *)realloc(user_input, buffer_counter+1);
				user_input[buffer_counter] = '\0';
				break;
			}

			buffer_counter++;
		}
		if(buffer_size < 0){
			throwError("Error reading");
		}

		append_command(prev_commands, user_input, &prev_commands_index);

		int command_index = generateIndex(user_input);
		switch(command_index){
			case 0:
				helloWorld();
				break;
			/*
			 * case 1:
			 *	command();
			 *	break
			 * .
			 * .
			 * .
			 */
			default:
				write(STDERR_FILENO, cmdnf, strlen(cmdnf));
		}
	}
	return 0;
}
