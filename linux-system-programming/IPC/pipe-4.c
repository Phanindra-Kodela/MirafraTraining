// this is a program to build a pipeline to execute : ls | grep ".c"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){

    // pipe descriptors
    int fd[2];

    // pipe failure
    if(pipe(fd) == -1){
        perror("pipe");
        exit(0);
    }

    // create a child process
    pid_t p1 = fork();

    if(p1 == 0){
        // child process
        // execute ls command

        // duplicate STDOUT_FILENO fd to pipe write descriptor
        dup2(fd[1], STDOUT_FILENO);

        // close the pipe desriptors
        close(fd[1]);
        close(fd[0]);

        // change the running process instance to execute ls program 
        char *args[] = {"ls", NULL};
        execvp("ls", args);

        // exec() fails
        perror("execvp");
        _exit(EXIT_FAILURE);
    }

    // create a child process
    pid_t p2 = fork();

    if(p2 == 0){
        // child process
        // execute grep cmd

        // duplicate stdin of grep to pipe read descriptor.
        dup2(fd[0], STDIN_FILENO);

        // close the pipe descriptors
        close(fd[1]);
        close(fd[0]);

        // change the program to grep
        char* args[] = {"grep", ".c", NULL};
        execvp("grep", args);

        // exec() fails
        perror("execvp");
        _exit(EXIT_FAILURE);
    }

    // closes parents pipe descriptors
    close(fd[0]);
    close(fd[1]);

    // waits for the child processes
    // specific process pid can be ignored because as the pipe takes care of the 
    // synchronization naturally with blocking behavior on read, write on pipe.
    wait(NULL);
    wait(NULL);

    return 0;
}