// this is a program to show child process becomes a zombie
#include <stdio.h> //printf()
#include <unistd.h> // fork(), getpid(), getppid()
#include <stdlib.h> // exit()
int main(){

    pid_t pid = fork();

    if(pid == 0){
        //child process
        printf("child exiting...\n");
        exit(0);
    }else{
        sleep(20);
    }

    return 0;
}