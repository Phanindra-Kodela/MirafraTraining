// this program handles SIGINT using modern signal API sigaction

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void handler(int sig){
    printf("Caught SIGINT\n");
}

int main(){
    // install signal handler - older implementation
    // signal(SIGINT, handler);

    struct sigaction sa;
    sa.sa_handler = handler;    // signal handler function
    sigemptyset(&sa.sa_mask); // other signals to be blocked while my handler is running
    sa.sa_flags = 0;    // options to modify the signal behavior

    sigaction(SIGINT, &sa, NULL); // modern signal API
    while(1){
        sleep(1);
        printf("running\n");
    }
    
    return 0;
}