/*
 * josh :)
 *    list*: this new command will clear the terminal screen
 *    and print a detailed list of all content of the current directory
 *    (like ls -l) to the terminal and a file called tree.txt
 *    after creating it.
 */

//so ls -l, write to tree.txt, then print? i think?

#include "list.h"

void list() {
    system("clear");

    int seed = creat("tree.txt", S_IRWXU); //opens or creates tree.txt for writing or overwriting.

    int pid_ls = fork();

    if (pid_ls < 0){
        fprintf(stderr, "parent process could not be forked. abort...\n");
        exit(0);
    }
    else if (pid_ls == 0) { //child
        dup2(seed, 1);
        char *new_argv[] = {"ls", "-l", 0};
        execvp(new_argv[0], new_argv);
        fprintf(stderr, "child (ls -l) failed. abort...\n");
        exit(0);
    }
    else { //parent
        close(seed);
        wait(NULL);
        FILE *file = fopen("tree.txt","r");
        if (file == NULL) {
            printf("file tree.txt not found. abort...\n");
            exit(0);
        }

        char c;
        c = fgetc(file);
        while (c != EOF) {
            printf("%c", c);
            c = fgetc(file);
        }

        fclose(file);
    }
}
