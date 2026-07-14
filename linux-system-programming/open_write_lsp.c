#include <unistd.h>
#include <fcntl.h>

int main(){

    int fd = open("out.txt", O_WRONLY | O_CREAT, 0644);
    write(fd, "Linux System Programming\n", 26);
}