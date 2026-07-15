// this is a program to read from a file by child and parent processes.
#include <stdio.h> // printf()
#include <unistd.h> // fork(), read(), std fd macros 
#include <fcntl.h> // open()

int main(){

    // open a fd to read from a file
    int fd = open("log.txt", O_RDONLY);
    if(fd == -1) { perror("open"); return 1; }

    pid_t pid = fork();

    char buff[100];
    if(pid == 0){
        //child's process
        //read 5 bytes from the fd.
        read(fd, buff, 5);
        printf("Child read:%s\n", buff);
    }
    else{
        //parent's process
        //read 5 bytes from the fd.
        read(fd, buff, 5);
        printf("Parent read:%s\n", buff);
    }
    return 0;
}