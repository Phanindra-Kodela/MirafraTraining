// this is a program to create pipe, write into it and read from it

#include <unistd.h> //pipe()
#include <stdio.h> //perror() write() read() STDOUT_FILENO
#include <stdlib.h> //EXIT_FAILURE

int main(){

    int fd[2];
    
    // create a pipe
    int p = pipe(fd);
    if(p == -1){
        perror("pipe");
        _exit(EXIT_FAILURE);
    }

    // write into pipe
    write(fd[1], "Phani", 5);
    
    // read from pipe
    char buf[100];
    int n_bytes = read(fd[0], buf, 5);
    
    // write into stdout
    write(STDOUT_FILENO, buf, n_bytes);

    return 0;
}