#include <stdio.h> // printf(), perror()
#include <unistd.h> // standard file descriptor macros, write()
#include <fcntl.h> // open()

int main(){

    int fd = open("log.txt", O_WRONLY | O_CREAT);

    if(fd == -1) { perror("open"); return 1; }

    // use dup2() to redirect stdout to log.txt file
    dup2(fd, STDOUT_FILENO);

    // writes to the redirected stdout
    printf("Hello from printf()\n");

    //write to log.txt file
    write(fd, "Hello from write()\n", 19);

    close(fd);

    return 0;
}