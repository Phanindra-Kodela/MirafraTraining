// this is a program where parent waits for the child process and collects the status returned by the child process.
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){

    pid_t pid = fork();

    if(pid == 0){
        //child process
        printf("Child Entered...\n");
        printf("Child is Exiting...\n");
        exit(11);
    }
    else{
        //parent process
        int status;
        wait(&status); // wait for a child to complete and get the status.
        // uses linux kernel macros to decode information safely.
        if(WIFEXITED(status)){
            printf("Normal exit...\n");
        }
        int code = WEXITSTATUS(status);
        printf("child returned status code: %d\n", code);
        
    }  

    return 0;
}