/* Multi Queue Header */

#include "./que.h"
#include <stdbool.h>

// structure definitions
/* structure of a Multi Queue
mq.[i] will have ith priority queue */
typedef struct
{
    struct Queue *list;
    int len;
} MultiQ;

// function definitions
/* creates a list of num Queues, each of which is empty. */
MultiQ createMQ(int num);

/* adds t to the Queue corresponding to priority p in mq. 
Task includes a TaskID tid and a priority p. */
MultiQ addMQ(MultiQ mq, Task t);

/* returns the front of the non-empty Queue in mq with the highest priority. */
Task nextMQ(MultiQ mq);

/* deletes the front of the non-empty Queue in mq with the highest priority; 
returns the modified MultiQ */
MultiQ delNextMQ(MultiQ mq);

/* tests whether all the Queues in mq are empty */
bool isEmptyMQ(MultiQ mq);

/* returns the total number of items in the MultiQ */
int sizeMQ(MultiQ mq);

/* returns the number of items in mq with the priority p. */
int sizeMQbyPriority(MultiQ mq, Priority p);

/* returns the Queue with priority p. */
struct Queue getQueueFromMQ(MultiQ mq, Priority p);