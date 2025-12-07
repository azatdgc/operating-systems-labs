#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    char buffer[100];
    int fd = open("input.txt", O_RDONLY);

    if (fd < 0) {
        perror("open");
        return 1;
    }

    int bytes = read(fd, buffer, sizeof(buffer));
    write(1, buffer, bytes);

    close(fd);
    return 0;
}
