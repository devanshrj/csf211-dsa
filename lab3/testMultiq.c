/* Driver for MultiQ */

#include "./multiq.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>           // for gettimeofday()

#define NUM 10

/* reads from f a list of pairs (task_id, priority) and adds each item to a MultiQ appropriately. */
MultiQ loadData(FILE *f) {
    // initialise a MultiQ
    MultiQ mq = createMQ(NUM);

    while (!feof(f)) {
        // take input from file of the formal "TaskID, Priority\n"
        // store values in a task object directly
        Task t;
        fscanf(f, "%d, %d ", &t.tid, &t.p);

        // add the task to MultiQ
        mq = addMQ(mq, t);
    }
    return mq;
}

MultiQ testDel(MultiQ mq, int num) {
    // perform delNextMQ num times
    while (num--) {
        mq = delNextMQ(mq);
    }
    return mq;
}

int main(int argc, char *argv[]) {
    // Create a file pointer and open the file read as command line argument.
    FILE *fileptr = fopen(argv[1], "r");

    struct timeval t1, t2;
    double elapsedTime;

    // loading operation
    // start timer
    gettimeofday(&t1, NULL);

    MultiQ mq = loadData(fileptr);

    // stop timer
    gettimeofday(&t2, NULL);

    // compute and print the elapsed time in millisec
    elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
    elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
    printf("Total time for loading data is %fms.\n", elapsedTime);

    // deletion
    // start timer
    gettimeofday(&t1, NULL);

    int del = 5;
    mq = testDel(mq, del);

    // stop timer
    gettimeofday(&t2, NULL);

    // compute and print the elapsed time in millisec
    elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
    elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
    printf("Total time for deleting %d tasks is %fms.\n", del, elapsedTime);
}