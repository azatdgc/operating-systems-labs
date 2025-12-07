#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Before execl()\n");

    // Replace current process with /bin/ls
    execl("/bin/ls", "ls", "-l", NULL);

    // If execl() fails, this line will execute
    perror("execl");
    return 1;
}
