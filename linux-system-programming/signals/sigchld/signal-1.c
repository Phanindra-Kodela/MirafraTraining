// this program handles SIGCHLD signal received from kernel when child processes exit

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/wait.h>

volatile sig_atomic_t stop = 0;

// SIGINT handler
void handler(int sig){
    stop = 1;
}

void child_handler(int sig){

    // reaps the exited child processes.
    pid_t pid;
    while((pid = waitpid(-1, NULL, WNOHANG)) > 0){
        printf("Reaped child process id = %d\n", pid);
    }
}

int main(){

    // install the sigaction variables to handles signals SIGCHLD, SIGINT
    struct sigaction sa = {0}, sb = {0}; // sa.sa_flags = sb.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    sigemptyset(&sb.sa_mask);

    sa.sa_handler = handler;
    sb.sa_handler = child_handler;

    // install SIGCHLD, SIGCHLD sigaction api handlers
    sigaction(SIGINT, &sa, NULL);
    sigaction(SIGCHLD, &sb, NULL);

    // creates a child process
    pid_t pid = fork();

    if(pid == 0){
        sleep(rand()%5);
        _exit(0);
    }else{
        pid_t pid = fork();
        if(pid == 0){
            // second child
            sleep(rand()%5);
            _exit(0);
        }
        else{
            pid_t pid = fork();
            if(pid == 0){
                // third child
                sleep(rand()%5);
                _exit(0);
            }
        }

        while(!stop){
            sleep(1);
            write(1, "Parent Still running...\n", 24);
        }
    }

    return 0;
}