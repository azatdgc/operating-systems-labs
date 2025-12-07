#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        printf("Child exiting immediately...\n");
    } else {
        sleep(5); // parent does not call wait()
        printf("Check zombie using: ps -l\n");
    }

    return 0;
}
