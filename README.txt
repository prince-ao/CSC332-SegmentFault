Stash
---
stash is a fast, post-modern shell written in C

Requirements
---
> Linux Operating System
> Just: https://github.com/casey/just
> GCC

Running stash as a developer
---
1. Clone the repository
2. Run `just run`

To developers
---
There exists an example command called hello, use that as an example.

To add a command to stash you must follow the steps below:
	1. Write the command in commands/ as <command_name>.c and <command_name>.h
	2. Go to commands.h and include <command_name>.h
	3. Go to main.c, increment `commands.command_size` in line #26 and add your command as commands.commands[n] = "..." under line #28;
	4. Still in main.c, add a case statement for n that calls the function you created in <command_name>.c
	5. Test all the commands before pushing.
