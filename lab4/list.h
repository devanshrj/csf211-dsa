/* Linked list header */

#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "memory.h"

// structure definitions
struct node {
    int element;
    struct node *next;
};

typedef struct {
    struct node* first;
    int count;
} linkedList;

// function definitions
/* Generates n random numbers and stores them in a linear linked list ls and returns ls */
linkedList createList(int n);

/* Decides whether ls must be linear or cyclic. 
If it must be cyclic, picks a random number, say r, and lets the last node in ls point to the rth node from the head node. 
If it must be linear, returns ls as is. */
linkedList createCycle(linkedList ls);

#endif