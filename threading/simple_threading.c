#include<stdio.h>
#include<pthread.h>
#include <unistd.h>     // sleep()

#define NUM_THREADS 5


// FUNCTION PROTOTYPES
void *job(void *);


void main() {
    pthread_t threadlist[NUM_THREADS];

    // Creating threads
    for (int ctr = 1; ctr <= NUM_THREADS; ctr++) {
        pthread_create(&threadlist[ctr-1], NULL, job, (void *) &ctr);
    }

    // Joining all threads
    for (int i = 0; i < 5; i++) {
        pthread_join(threadlist[i], NULL);
    }
}


void *job(void *time_in_seconds) {
    int sleeptime = *(int *)time_in_seconds;
    printf(">>> Sleeping for %d seconds...\n", sleeptime);
    sleep(sleeptime);
    printf(">>> Done sleeping for %d seconds...\n", sleeptime);
}
