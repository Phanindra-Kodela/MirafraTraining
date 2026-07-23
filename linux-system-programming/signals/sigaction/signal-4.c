// this program uses sig_atomic_t in signal handler to read and write atomically 
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

volatile sig_atomic_t stop = 0;
long long cnt = 0;

void handler(int sig){
    stop = 1;
}

int main(){

    struct sigaction sa;
    sa.sa_handler = handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    sigaction(SIGINT, &sa, NULL);

    while(!stop){
        cnt++;
        write(1, ".\n", 2);
    }

    // to measure how many times . has printed
    char buf[1024];
    sprintf(buf, "%lld", cnt); // formatted buffer.
    write(1, buf, strlen(buf));

    return 0;
}