// this is a program to execute pwd program using execvp()
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){

    pid_t pid = fork();

    if(pid == 0){
        // child process
        //execute pwd program use execvp();
        char *args[] = {"pwd", NULL};
        execvp("pwd", args); //searches PATH env variable for the file "pwd"
        // if execvp() failed
        perror("execvp");
        _exit(EXIT_FAILURE);
        printf("This should be never printed");
    }else{
        //parent process
        wait(NULL); // wait for the child process
        printf("Successfully executed the child program\n");
    }

    return 0;
}