#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* thread_function(void* arg) {
    printf("Thread running: %ld\n", pthread_self());
    return NULL;
}

int main() {
    pthread_t thread;

    // Create a thread
    if (pthread_create(&thread, NULL, thread_function, NULL) != 0) {
        perror("pthread_create");
        return 1;
    }

    printf("Main thread continues...\n");

    // Wait for the created thread
    pthread_join(thread, NULL);

    printf("Thread finished.\n");

    return 0;
}
