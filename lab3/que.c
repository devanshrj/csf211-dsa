/* Queue Implementation using Linked List */

#include "./que.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct Queue *newQ() {
    struct Queue *q = (struct Queue *) malloc(sizeof(struct Queue));
    q->count = 0;
    q->head = NULL;
    q->tail = NULL;
    
    return q;
}

bool isEmptyQ(struct Queue *q) {
    if (q->count)
        return false;
    return true;
}

struct Queue *addQ(struct Queue *q, Element e) {
    // create a node
	struct node *new = (struct node *)malloc(sizeof(struct node));
	// creating a node whose address is being stored in the new pointer.

	new->element = e;
    new->next = NULL;
    
	q->count++;

    // if list is non empty
	if (q->tail != NULL) {
        (q->tail)->next = new;
        q->tail = new;
    } else {
        q->head = q->tail = new;
    }
    
    return q;
}

struct Queue *delQ(struct Queue *q) {
    if (isEmptyQ(q)) {
        printf("Error! Queue is empty!\n");
        exit(1);
    }

    q->head = (q->head)->next;
    q->count--;

    if (q->head == NULL) {
        q->tail = NULL;
        q->count = 0;
    }

    return q;
}

int front(struct Queue *q) {
    if (isEmptyQ(q)) {
        printf("Error! Queue is empty!\n");
        exit(1);
    }
    return (q->head)->element;
}

int lengthQ(struct Queue *q) {
    return q->count;
}

void printQ(struct Queue *q) {
    if (isEmptyQ(q)) {
        printf("Error! Queue is empty!\n");
        exit(1);
    }

    struct node *ptr = q->head;
	printf("\n[ ");
	// start from the beginning
	while (ptr != NULL)
	{
		printf("%d, ", ptr->element);
		ptr = ptr->next;
	}
	printf("]\n");
}