// this is a program to demonstrate signal handlers are inherited using fork()

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

void handler(int sig){
    printf("\nCaught signal %d", sig);
}

int main(){

    signal(SIGINT, handler);

    pid_t pid = fork();

    if(pid == 0){
        // child process
        printf("Entered Child process: \n");

        // child inherits signal dispositions.
        while(1){
            printf("running...\n");
            sleep(1);
        }
    }
    else{
        // parent process
        wait(NULL);
        printf("Parent Process Exited.\n");
    }

    return 0;
}