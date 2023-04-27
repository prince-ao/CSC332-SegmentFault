#include "exit.h"

void exitcmnd(){

printf("Last 3 commands:\n");
  for (int i = 0; i < 3 && commands[i] != NULL; i++) {
        printf("%s\n", commands[i]);
    }
   
  int pid_ls = fork();

    if (pid_ls < 0){
        fprintf(stderr, "Parent process could not be forked.\n");
        exit(0);
    }
    else if (pid_ls == 0) { 
        dup2(seed, 1);
        char *new_argv[] = {"ls", "-l", 0};
        execvp(new_argv[0], new_argv);
        fprintf(stderr, "child (ls -l) failed...\n");
        exit(0);
    }
  else { 
        close(seed);
        wait(NULL);
 }
