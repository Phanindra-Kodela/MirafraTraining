// Create a file with O_CREAT | O_TRUNC, write "Hello\n" to it, close it, reopen it with O_APPEND, write "World\n"

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(){

    // open a existing file or create a file and open it
    int fd = open("data.txt", O_WRONLY|O_TRUNC, 0755);

    // can't open the file.
    if(fd == -1){
        perror("open");
        return 1;
    }

    write(fd, "Hello\n", 6);
    close(fd);
    fd = open("data.txt", O_WRONLY|O_APPEND, 0755);
    write(fd, "World\n", 6);
    close(fd);

    return 0;
}