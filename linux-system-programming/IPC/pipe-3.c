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
        close(fd[0]); // good practice to close fds after use
    }else{
        // parent
        // close its own read descriptor otherwise nothing
        close(fd[0]); // good practice to close unused fds

        // write to fd[1]
        write(fd[1], "Hello Child\n", 13);

        write(fd[1], "Linux\n", 6);
        write(fd[1], "System\n", 7);
        write(fd[1], "Programming\n", 12);

        // close write descriptor so read() doesn't get blocked.
        close(fd[1]);

        // to avoid orphan process, reaps child
        wait(NULL);
    }

    return 0;
}