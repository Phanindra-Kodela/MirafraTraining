// this is a program to share open file description between two file descriptors.
#include <stdio.h>
#include <unistd.h> //write()
#include <fcntl.h> // open()

int main(){

    // open the file
    int fd1 = open("sample.txt", O_RDONLY);
    if(fd1 == -1){
        perror("open");
        return 1;
    }

    // share the open file description
    int fd2 = dup(fd1);

    char buf[100];
    // read & write 5 bytes from fd1
    read(fd1, buf, 5);
    write(1, buf, 5); // stdout

    // read & write 5 bytes from fd2
    read(fd2, buf, 5);  // buf is to store the 5 bytes read from fd2
    write(1, buf, 5);

    //close one of fds and continue reading
    close(fd1);

    read(fd2, buf, 5);
    write(1, buf, 5);

    // close the shared fd as well
    close(fd2);

    //trying reading from a closed fd, it returns -1 because fd is not valid.
    int cnt = read(fd2, buf, 5);
    write(1, buf, 5); // this dupilcates the previous write() as buf is not changed.
    printf("%d", cnt);
    return 0;
}