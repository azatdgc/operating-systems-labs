#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("test.txt", O_CREAT | O_WRONLY, 0644);

    if (fd < 0) {
        perror("open");
        return 1;
    }

    char *msg = "Hello from open() example!\n";
    write(fd, msg, 28);

    close(fd);
    return 0;
}
