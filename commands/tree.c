#include "tree.h"

void tree() { 
    char dir0[]="DIR0";
    char dir1[]="DIR1";

    if (access(dir0, F_OK) == 0){
        printf("'%s' is already created\n", dir0);
    }
    else{
        mkdir("./DIR0", 0777);
    }
    
    if (access(dir1, F_OK) == 0){
        printf("'%s' is already created\n", dir1);
    }
    else{
        mkdir("./DIR0/DIR1", 0777);
    }
} 