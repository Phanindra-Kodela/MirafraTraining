// this is a program where the child executes other program using execvp()
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(){

    printf("Parent Running\n");
    
    //create a process
    pid_t pid = fork();

    if(pid == 0){
        // child process
        // execute ls -l
        char *args[] = {"ls", "-l", NULL}; 
        execvp("ls", args);

        //execvp fails
        perror("execvp");
        _exit(EXIT_FAILURE);
    }else{
        wait(NULL);
        printf("Child finished execution\n");
        printf("Parent terminating...\n");
    }

    return 0;
}