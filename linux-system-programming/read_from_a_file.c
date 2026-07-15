#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(){

    // open a file in read only mode with permissions 755 and allocate a file descriptor to it.
    int fd = open("sample.txt", O_RDONLY, 0755);

    // if open() fails
    if(fd == -1){
        // send open error note to stdout.
        perror("open");
        return 1;
    }

    // read the file and write it to the stdout
    char buf[100];
    ssize_t cnt = read(fd, buf, 10);
    // till EOF 
    while(cnt != 0){
        // write the buffer read from read, to stdout
        write(1, buf, cnt);
        cnt = read(fd, buf, 10);
    }
    // close the fd so that you don't run out of available descriptors
    close(fd);
    return 0;
}