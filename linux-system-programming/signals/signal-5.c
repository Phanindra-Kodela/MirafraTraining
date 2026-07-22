// this is a program to run a different program in child process with inherited signal dispositions
#include <stdio.h>
#include <unistd.h>  // fork()
#include <sys/wait.h> // wait()
#include <signal.h> // signal()

void handler(int sig){
    printf("process = %d\n", getpid());
    printf("Caught signal = %d\n", sig);
}

int main(){

    signal(SIGINT, handler);
    pid_t pid = fork();

    if(pid == 0){
        // child process
        printf("child process\n");
        char *args[3] = {"sleep", "10", NULL};
        execvp("sleep", args);
    }else{

        wait(NULL);
        while(1){
            printf("Parent Running\n");
            sleep(1);
        }
    }

    return 0;
}