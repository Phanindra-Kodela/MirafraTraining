// this is a program to ignore signal interrupt
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main(){

    // ignores signal interrupt
    signal(SIGINT, SIG_IGN);

    while(1){
        puts("running...");
        sleep(1);
    }

    return 0;
}