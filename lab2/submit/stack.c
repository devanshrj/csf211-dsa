/* Stack operations */

#include "stack.h"
#include <stdlib.h>

void push(struct linkedList *head, int ele) { 
    insertFirst(head, ele);
}

struct node * pop(struct linkedList *head)
{
    if (!head->count) {
        printf("Stack empty!\n");
        exit(1);
    }
    return deleteFirst(head);
}

void printStack(struct linkedList *head) {
    printList(head);
}