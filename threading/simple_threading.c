/*
Simple Threading Demo Code in C
Achieved via POSIX Threading (pthread)

This program creates threads with varying 'job' times -- really it's just sleeping, 
and outputs -- really 'joining' thre threads -- as soon as they are finished with their job. 

Copyright(c) Taks Joseph Refugio
Developer contact: taksjosephrefugio@gmail.com
*/
#include<stdio.h>
#include<stdlib.h>      // malloc()
#include<pthread.h>
#include <unistd.h>     // sleep()
#define NUM_THREADS 5


// FUNCTION PROTOTYPES
int *build_sleeptime_arr(int);
void *job(void *);


void main() {
    pthread_t threadlist[NUM_THREADS];
    int *sleeptime_list = build_sleeptime_arr(NUM_THREADS);

    // Creating threads
    for (int ctr = 0; ctr < NUM_THREADS; ctr++) {
        pthread_create(&threadlist[ctr], NULL, job, (void *) &sleeptime_list[ctr]);
    }

    // Joining all threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threadlist[i], NULL);
    }
}


// This routine describes what each thread is doing
void *job(void *time_in_seconds) {
    int sleeptime = *(int *)time_in_seconds;
    printf(">>> Sleeping for %d seconds...\n", sleeptime);
    sleep(sleeptime);
    printf(">>> Done sleeping for %d seconds...\n", sleeptime);
}


// Returns an list of incrementing sleeptimes beginning with '1'  and ending with 'num_threads'
int *build_sleeptime_arr(int num_threads) {
    int *retval = (int *)malloc(num_threads * sizeof(int));
    for (int ctr = 0; ctr < num_threads; ctr++) { retval[ctr] = ctr + 1; }
    return retval;
}
