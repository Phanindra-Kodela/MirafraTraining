// this is a program to print parent process id and child's process id
#include <stdio.h>
#include <unistd.h> // fork(), getpid(), getppid()

int main(){

    // get process id
    pid_t pid = fork();

    if(pid == 0){
        // child's process
        // print child's pid and its parent's pid
        printf("Child Id: %d\n", getpid());
        printf("Child's parent Id: %d\n", getppid());
    }
    else{
        // parent's process
        // printf parent pid and its child pid
        sleep(1);
        printf("Parent Id: %d\n", getpid());
        printf("Parent child Id: %d\n", pid);
    }

    return 0;
}