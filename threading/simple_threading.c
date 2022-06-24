#include<stdio.h>
#include<pthread.h>
#include <unistd.h>

void job(int sleeptime) {
    printf(">>> Sleeping for %d seconds...\n", sleeptime);
    sleep(sleeptime);
}

void main() {
    pthread_t single_thread;

    for(int x=1; x <= 5; x++) {
        job(x);
    }
}