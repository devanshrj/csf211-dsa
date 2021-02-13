/* Exercise 3: Linked List creation */

#include "list.h"

// using totalSize global variable from memory.c
extern long long totalSize;

linkedList createList(int n) {
    // create first node
    struct node *link = (struct node *) myalloc(sizeof(struct node));
    link->element = rand() % 100;
    link->next = NULL;

    // create a empty linked list 
    linkedList *ls = (linkedList *) myalloc(sizeof(linkedList));
    ls->first = link;
    ls->count = n;

    // loop to add remaining elements
    for (int i = 1; i < n; i++) {
        struct node *new = (struct node *) myalloc(sizeof(struct node));
        new->element = rand() % 100;
        new->next = NULL;
        link->next = new;
        link = new;
    }

    FILE *fptr = fopen("createList.txt", "w");
    fprintf(fptr, "Number of elements: %d\n", n);
    fprintf(fptr, "Heap space used by createList(): %lld", totalSize);
    fclose(fptr);

    return *ls;
}

linkedList createCycle(linkedList ls) {
    // programmtic coin toss
    srand(time(NULL));

    if (rand() < RAND_MAX / 2) {
        // printf("Linear list!\n");
        return ls;
    }

    // printf("Cyclic list!\n");

    // traverse list to find last element
    struct node *last = ls.first;
    while (last->next != NULL)
        last = last->next;

    // traverse to rth node from the beginning
    int r = rand() % 100, i = 1;
    struct node *temp = ls.first;
    
    while (i != r) {
        temp = temp->next;
        i++;
    }
    last->next = temp;

    return ls;
}