// this is a program on writing several strings to pipe and reading them back
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){

    // create 1d array of 2 elements
    int fd[2];

    // create a pipe and pass 1d array as argument
    int p = pipe(fd);

    //if pipe() fails
    if(p == -1){
        perror("pipe");
        _exit(EXIT_FAILURE);
    }

    // write multiple strings into pipe
    write(fd[1], "Inter", 5);
    write(fd[1], "Process", 7);
    write(fd[1], "Communication", 13);

    // create a buff for reading
    char buff[100];
    // read from pipe
    read(fd[0], buff, 5);
    write(STDOUT_FILENO, buff, 5);

    read(fd[0], buff, 7);
    write(STDOUT_FILENO, buff, 7);

    read(fd[0], buff, 13);
    write(STDOUT_FILENO, buff, 13);

    return 0;
}