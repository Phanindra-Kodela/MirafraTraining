// this is a program to raise a signal interrupt

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void handler(int sig){
    printf("\nCaught Signal %d\n", sig);
}
int main(){

    signal(SIGINT, handler);
    while(1){
        printf("running...");
        sleep(1);
        raise(SIGINT);
    }

    return 0;
}