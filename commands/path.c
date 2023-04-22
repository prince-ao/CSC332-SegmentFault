#include "path.h"

void path() {
    char* cwd = (char*) malloc(sizeof(char) * PATH_MAX);
    if (getcwd(cwd, PATH_MAX) == NULL) {
        printf("Error: could not find the current directory\n");
        return;
    }
    printf("%s\n", cwd);

    // Write path to file
    FILE* f = fopen("path.txt", "w");
    if (f == NULL) {
        printf("Error: could not open file\n");
        return;
    }
    fprintf(f, "%s\n", cwd);
    fclose(f);

    free(cwd);
}
