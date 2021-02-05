/* Multi Queue implementation using que.c */

#include "./multiq.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

MultiQ createMQ(int num) {
    MultiQ mq;
    struct Queue *list = (struct Queue *) malloc(sizeof(struct Queue) * (num + 1));

    mq.list = list;
    mq.len = num;

    return mq;
}

MultiQ addMQ(MultiQ mq, Task t) {
    mq.list[t.p] = *addQ(&mq.list[t.p], t);

    return mq;
}

Task nextMQ(MultiQ mq) {
    for (int i = mq.len; i >= 1; i--) {
        if (lengthQ(&mq.list[i])) {
            return front(&mq.list[i]);
        }
    }

    // if all queues are empty
    printf("Error! All queues are empty!");
    exit(1);
}

MultiQ delNextMQ(MultiQ mq) {
    for (int i = mq.len; i >= 1; i--) {
        if (lengthQ(&mq.list[i])) {
            mq.list[i] = *delQ(&mq.list[i]);
            return mq;
        }
    }

    // if all queues are empty
    printf("Error! All queues are empty!");
    exit(1);
}

bool isEmptyMQ(MultiQ mq) {
    for (int i = mq.len; i >= 1; i--) {
        if (!isEmptyQ(&mq.list[i])) {
            return false;
        }
    }
    return true;
}

int sizeMQ(MultiQ mq) {
    int size = 0;
    for (int i = 1; i <= mq.len; i++) {
        size += lengthQ(&mq.list[i]);
    }
    return size;
}

int sizeMQbyPriority(MultiQ mq, Priority p) {
    return lengthQ(&mq.list[p]);
}

struct Queue getQueueFromMQ(MultiQ mq, Priority p) {
    return mq.list[p];
}