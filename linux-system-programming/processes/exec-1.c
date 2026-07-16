//this is a program to execute date program using execl()

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){

    pid_t pid = fork();
    if(pid == 0){
        //child process
        // execute date program
        execl("/usr/bin/date", "date", NULL);
        perror("execl");
        _exit(EXIT_FAILURE);
        printf("This won't be printed!!");
    }
    else{
        //parent process
        wait(NULL);
        printf("Parent executed child program\n");
    }

    return 0;
}