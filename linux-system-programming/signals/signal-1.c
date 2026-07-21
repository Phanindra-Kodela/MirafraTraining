// this is a program to handle a SIGINT signal

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

// signal handler to handle sig signal
void handler(int sig){
    printf("Caught signal %d\n", sig);
}

int main(){

    //diverts the default action of SIGINT to a handler
    signal(SIGINT, handler);

    while(1){
        puts("Running");
        sleep(1);
    }

    return 0;
}