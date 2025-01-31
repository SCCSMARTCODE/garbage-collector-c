// Entry point for testing the GC
#include "gc.h"

void *gc_thread_function(void *arg) {
    (void)(arg);
    while (1) {
        sleep(2); // Run GC every 2 seconds
        pthread_mutex_lock(&gc_mutex);
        gc_collect();
        pthread_mutex_unlock(&gc_mutex);
    }
    return NULL;
}

int main() {
    pthread_t gc_thread;
    pthread_create(&gc_thread, NULL, gc_thread_function, NULL);

    printf("\n🔵 Allocating memory...\n");
    int *num1 = (int *)gc_malloc(sizeof(int));
    int *num2 = (int *)gc_malloc(sizeof(int));

    *num1 = 42;
    *num2 = 99;

    printf("[MAIN] num1 = %d, num2 = %d\n", *num1, *num2);

    sleep(3);

    printf("\n🟡 Unreferencing num1 and num2...\n");
    num1 = NULL;
    num2 = NULL;

    sleep(5);

    printf("\n🟢 Allocating more memory...\n");
    int *num3 = (int *)gc_malloc(sizeof(int));
    *num3 = 77;

    printf("[MAIN] num3 = %d\n", *num3);

    sleep(5);

    pthread_cancel(gc_thread);
    pthread_join(gc_thread, NULL);

    return 0;
}