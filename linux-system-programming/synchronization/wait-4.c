// this is a program to collect two child processes exit codes
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main(){

    // create a child process
    pid_t pid = fork();

    if(pid == 0){
        //child process
        exit(23);
    }
    else{
        // create another child process
        pid_t pid2 = fork();
        
        if(pid2 == 0){
            //child process;
            exit(11);
        }
        int status;
        // reap each child.
        pid_t child;
        while((child = wait(&status)) > 0){
            printf("Child collected: %d\n", child);
            if(WIFEXITED(status)){
                printf("Exit code = %d\n", WEXITSTATUS(status));
            }
        }
    }

    return 0;
}