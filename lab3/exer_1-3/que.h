/* Queue Header */

#include "./Element.h"
#include <stdbool.h>

// structure definitions
/* structure of a linked list node. It contains an element */
struct node
{
    Element element;
    struct node *next;
};

/* structure of a queue implemented using a linked list.
 * Stores the count of number of elements in the list and also a pointer link to the first node and last node of the list. */
struct Queue
{
    int count;
    struct node *head;
    struct node *tail;
};

// function definitions
/* returns an empty Queue */
struct Queue *newQ();

/* tests whether q is empty */
bool isEmptyQ(struct Queue *q);

/* adds e to the rear of the Queue; returns the modified Queue */
struct Queue *addQ(struct Queue *q, Element e);

/* deletes the element from the front of the Queue; returns the modified Queue */
struct Queue *delQ(struct Queue *q);

/* returns the element from the front of the Queue */
Element front(struct Queue *q);

/* returns the length of the Queue */
int lengthQ(struct Queue *q);

/* print the Queue */
void printQ(struct Queue *q);