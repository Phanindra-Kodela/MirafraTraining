// this is a program where parent and child perform some operations on the same variable.
#include <stdio.h>
#include <unistd.h>

int main(){

    int x = 100;

    pid_t pid = fork();

    if(pid == 0){
        //child process
        x -= 20;
        printf("Child x: %d\n", x);
    }
    else{
        // parent process
        x += 10;
        printf("Parent x: %d\n", x);
    }

    return 0;
}