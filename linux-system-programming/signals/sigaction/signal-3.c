// this program shows SIGTERM signal is blocked while handling SIGINT using modern signal API sigaction. 

#include <stdio.h>
#include <signal.h>
#include <unistd.h> // to use async-signal-func like write();
#include <string.h>

void handler(int sig){
    // write(int fd, char* buf, size_t num_bytes)
    char *buffer = "Caught Signal SIGINT\n";
    int size_buffer = strlen(buffer);
    write(1,  buffer, size_buffer);
    
    // current handler is taking some time...
    sleep(5);
    
    buffer = "Handled SIGINT Signal\n";
    size_buffer = strlen(buffer);
    write(1, buffer, size_buffer);
}

int main(){

    // declare sigaction struct variable
    struct sigaction sa;
    sa.sa_handler = handler; // assign the installed handler.
    sigemptyset(&sa.sa_mask); // doesn't block any additional signals.
    // except current one automatically to avoid recursive execution of the handler.
    // and naturally SIGTERM interrupts the current handler.

    // to block SIGTERM signal only while current handler is executing.
    sigaddset(&sa.sa_mask, SIGTERM);
    
    sa.sa_flags = 0; // default options

    // catch the signal
    sigaction(SIGINT, &sa, NULL);

    while(1){
        sleep(1);
        write(1, "running\n", 8);
    }

    return 0;
}