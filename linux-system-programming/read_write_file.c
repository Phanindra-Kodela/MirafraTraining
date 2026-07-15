// Write a program that copies one file to another using only open(), read(), write() and close()

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(){

    // open a file to read from and assign fd to it.
    int in_fd = open("sample.txt", O_RDONLY, 0755);
    
    // open a file to write into and assign fd to it.
    int out_fd = open("output.txt", O_WRONLY | O_CREAT, 0755);

    // some file open error.
    if(in_fd == -1 || out_fd == -1){
        perror("open");
        return 1;
    }

    // read a file
    char buf[100];
    ssize_t cnt = read(in_fd, buf, 99);

    // write to a file while reading from another file
    while(cnt){
        write(out_fd, buf, 99);
        cnt = read(in_fd, buf, 99);
    }

    // close the fd's
    close(in_fd);
    close(out_fd);
    return 0;
}