#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd = open("out.txt", O_CREAT | O_WRONLY, 0644);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    int new_fd = dup(fd); // duplicate file descriptor

    write(fd, "Writing to original fd\n", 23);
    write(new_fd, "Writing to duplicated fd\n", 25);

    close(fd);
    close(new_fd);
    return 0;
}
