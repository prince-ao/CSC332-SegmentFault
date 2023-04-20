#include "tree.h"

void tree() {
    // mkdir("./DIR0", 0777);
    // mkdir("./DIR0/DIR1", 0777);


    // pid_t pid;

    // pid = fork();


    // if (pid == -1){
    //     printf('Fork Failed.');
    // }
    // if (pid == 0){
    //     mkdir("./DIR0", 0777);
    //     kill();
    // }
    // else{
        
    // }


    char dir0path[]="./DIR0";
    char dir1path[]="./DIR0/DIR1";

    if (access(dir0path, F_OK) != 0){
        printf("'%s' is already created\n", dir0path);
    }
    else{
        mkdir("./DIR0", 0777);
    }
    
    if (access(dir1path, F_OK) != 0){
        printf("'%s' is already created\n", dir1path);
    }
    else{
        mkdir("./DIR0/DIR1", 0777);
    }
} 