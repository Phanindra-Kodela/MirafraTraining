// this program shows signal dispositions are inherited across exec()

#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h> // EXIT_FAILURE
#include <unistd.h>
#include <signal.h>

int main(){

    // ignore SIGINT
    signal(SIGINT, SIG_IGN);

    pid_t pid = fork();
    
    if(pid == 0){
        // child process

        char* args[3] = {"sleep", "10", NULL};
        execvp("sleep", args);
        perror("execvp");
        _exit(EXIT_FAILURE);
    }else{

        // reap the child process.
        wait(NULL);
        while(1){
            sleep(1);
            printf("running\n");
        }
    }
    return 0;
}