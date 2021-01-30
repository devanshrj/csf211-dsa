/* Stack header */

#include "linkedlist.h"

/* insert element at the front of the list (top of stack) */
void push(struct linkedList *head, int ele);

/* remove the element at the front of the list (top of stack) */
struct node * pop(struct linkedList *head);

/* print the elements of the stack */
void printStack(struct linkedList *stack);
