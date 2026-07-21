// this is a program to raise a signal interrupt

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main(){

    while(1){
        printf("running...");
        sleep(1);
        raise(SIGINT);
    }

    return 0;
}