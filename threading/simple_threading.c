#include<stdio.h>
#include<pthread.h>
#include <unistd.h>     // sleep()

// FUNCTION PROTOTYPES
void *job(void *);


void main() {
    int sleeptime = 1;
    pthread_t single_thread;
    pthread_create(&single_thread, NULL, job, (void *) &sleeptime);
    pthread_join(single_thread, NULL);
}


void *job(void *time_in_seconds) {
    int sleeptime = *(int *)time_in_seconds;
    printf(">>> Sleeping for %d seconds...\n", sleeptime);
    sleep(sleeptime);
}
