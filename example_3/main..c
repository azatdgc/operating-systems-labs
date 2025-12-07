#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd = open("data.txt", O_RDONLY);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    lseek(fd, 5, SEEK_SET); // move 5 bytes forward

    char buffer[50];
    int bytes = read(fd, buffer, sizeof(buffer));

    write(1, buffer, bytes);

    close(fd);
    return 0;
}
