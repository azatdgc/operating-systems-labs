#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        printf("Child running...\n");
        sleep(2);
        printf("Child finished.\n");
    } else {
        wait(NULL);
        printf("Parent: Child completed.\n");
    }

    return 0;
}
