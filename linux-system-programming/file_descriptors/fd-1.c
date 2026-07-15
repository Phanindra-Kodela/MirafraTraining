// this is a program to open two instances of open file description

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(){

    char buf[100];

    int fd1 = open("sample.txt", O_RDONLY);
    int fd2 = open("sample.txt", O_RDONLY);

    if(fd1 == -1 || fd2 == -1){
        perror("open");
        return 1;
    }

    // read & write 5 bytes from the fd1
    read(fd1, buf, 5);
    write(1, buf, 5);
    
    // read & write 5 bytes form the fd2
    read(fd2, buf, 5);
    write(1, buf, 5);

    // close the fds
    close(fd1);
    close(fd2);
    
    return 0;
}