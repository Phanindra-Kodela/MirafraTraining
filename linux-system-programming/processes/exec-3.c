// this is a program to execute a unknown program
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){

    // create a child process
    pid_t pid = fork();

    printf("Creating a child process...");
    if(pid == 0){
        //child process
        //execute unknown program
        char *args[] = {NULL};
        execvp("unknown", args);
        //if execvp() fails
        perror("execvp");
        _exit(EXIT_FAILURE);
        printf("This is never printed");
    }else{
        wait(NULL); // reaps the child process
        printf("\nChild process terminated!\n");
    }

    return 0;
}