#include <unistd.h>
#include <fcntl.h>

int main(){

    int fd = open("out.txt", O_WRONLY | O_CREAT, 0644);
    if(fd == -1){
        perror("open");
        return 1;
    }
    write(fd, "Linux System Programming\n", 26);
    close(fd);
}