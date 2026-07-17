// this is a program on where parent writes and child reads

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(){

    int fd[2];

    if(pipe(fd) == -1){
        perror("pipe");
        _exit(0);
    }

    pid_t pid = fork();

    if(pid == 0){
        // child
        // closes its own write descriptor otherwise read gets blocked
        close(fd[1]);

        // read from pipe
        char buf[100];
        int n = read(fd[0], buf, sizeof(buf));

        // write to stdout 
        write(STDOUT_FILENO, buf, n);
        close(fd[0]);
    }else{
        // parent
        // close its own read descriptor otherwise nothing
        close(fd[0]);

        // write to fd[1]
        write(fd[1], "Hello Child", 11);

        // close write descriptor so read() doesn't get blocked.
        close(fd[1]);
        wait(NULL);
    }

    return 0;
}