#include "exit.h"

void exitcmnd(){
printf("The last 3 commands are:\n");
  for (int i = 0; i < 3 && commands[i] != NULL; i++) {
        printf("%s\n", commands[i]);
    }
  
  int pid_ls = fork();

    if (pid_ls < 0){
        fprintf(stderr, "Parent process could not be forked.\n");
        exit(0);
    }
    else if (pid_ls == 0) {
        char *new_argv[] = {"ls", "-l", 0};
        execvp(new_argv[0], new_argv);
        fprintf(stderr, "Child (ls -l) failed.\n");
        exit(0);
    }
  else { 
        wait(NULL);
 }

  printf("Press Return(Enter) to exit.\n");
    while (getchar() != '\n') {
        
    }
  printf("Exiting...\n");
    exit(0);
}
