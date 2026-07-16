// this is a program to execute a unknown program
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){

    printf("Hello");
    // executing unknown program
    char *args[] = {NULL};
    execvp("unknown", args);
    // executes only if execvp returns failure
    perror("execvp");
    // no cleanup
    _exit(EXIT_FAILURE);
    return 0;
}