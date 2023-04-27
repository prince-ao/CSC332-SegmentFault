#include"utilities.h"

char* getPrompt() {
	char* host = (char*)malloc(126 * sizeof(char)); // :)
	char* username = getlogin();
	if(gethostname(host, 126) < 0){
		host[0] = '\0';
	}
	time_t current_time;
	struct tm * time_info;
	char timeString[9];

	time(&current_time);
	time_info = localtime(&current_time);

	strftime(timeString, 9, "%H:%M:%S", time_info);


	char* res = (char*)malloc((strlen(host) + strlen(username) + strlen(timeString) + 10) * sizeof(char));
	snprintf(res, (strlen(host) + strlen(username) + strlen(timeString) + 7), "%s@%s %s ~> ", username, host, timeString);
	return res;
}

int main(void){
	command_vec commands;
	commands.command_size = 6; // update this with each command.
	commands.commands = (char**)malloc(commands.command_size * sizeof(char*));
	commands.commands[0] = "hello";
	commands.commands[1] = "tree";
    commands.commands[2] = "list"; //change to 3 later.
    commands.commands[3] = "kill"; //change to 5 when all commands are here.
	commands.commands[4] = "path";
	commands.commands[5] = "exit";
	/*
	commands.commands[2] = ...;
    commands.commands[3] = ...;
    commands.commands[4] = ...;
	*/
	char **prev_commands = (char **)malloc(MAX_COMMANDS * sizeof(char*));
	int prev_commands_index;
	char *user_input;
	char temp_buffer;
	int buffer_size;
	char *prompt;
	char *cmdnf = "Command Not Found\n";

	while(1){
		prompt = getPrompt();
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
		if(strlen(user_input) == 0){
			continue;
		}

		append_command(prev_commands, user_input, &prev_commands_index);

		int command_index = generateIndex(user_input, &commands);
		switch(command_index){
			case 0:
				helloWorld();
				break;
			case 1:
				tree();
				break;
      case 2: //change to 3 when the two prior commands are initialized
        list();
        break;
      case 3: //change to 5 when all the commands are initialized
         my_kill();
         break;
			case 4:
				 path();
				 break;
			case 5:
				exitcmnd();
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
