#include <stdio.h> // printf(), perror()
#include <unistd.h> // std fd macros, write()
#include <fcntl.h> // open()

int main(){

    int saved = dup(STDOUT_FILENO);
    int fd = open("log.txt", O_WRONLY | O_TRUNC);
    if(fd == -1) {perror("open"); return 1; }

    // redirect to stdout to a file log.txt
    dup2(fd, STDOUT_FILENO);
    //write something to the redirected terminal output
    write(STDOUT_FILENO, "Hello from redirected write()", 29);

    //restore the stdout terminal 
    dup2(saved, STDOUT_FILENO);
    //write something to the terminal.
    write(STDOUT_FILENO, "Hello from write() in terminal", 30);

    close(fd);
    return 0;
}