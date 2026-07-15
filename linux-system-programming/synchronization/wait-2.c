// this is a program where parent process waits for the child process to complete.
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(){

    pid_t pid = fork();
    if(pid == 0){
        printf("Child exiting...\n");
        exit(0);
    }else{
        wait(NULL); // collects a child process
        printf("Child Collected..\nParent exiting...\n");
    }
    return 0;
}