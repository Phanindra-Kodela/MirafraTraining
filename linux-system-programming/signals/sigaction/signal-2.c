// this program uses modern signal API
#include <stdio.h>
#include <string.h> //strlen()
#include <signal.h>
#include <unistd.h> // write()

void handler(int sig){
    printf("Caught SIGINT\n");
}

int main(){

    struct sigaction sa;
    sa.sa_handler = handler;
    sigaction(SIGINT, &sa, NULL);

    sigemptyset(&sa.sa_mask); // doesn't block any other signals while handling current signal handler.
    sa.sa_flags = SA_RESTART; // interrupted system call restarts by the kernel
    
    char buf[1024];
    fgets(buf, sizeof buf, stdin);
    
    write(1, buf, strlen(buf));
    return 0;
}