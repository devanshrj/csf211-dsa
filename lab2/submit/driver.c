/* Driver for Stack */

#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Create a file pointer and open the file read as command line argument.
    FILE *fileptr = fopen(argv[1], "r");

    // Declare a pointer to a stack (top) and allocate memory to it.
    struct linkedList *head = (struct linkedList *)malloc(sizeof(struct linkedList));
    head->first = NULL;
    head->count = 0;

    // stack insertion
    while (!feof(fileptr))
    {
        // read the next element and store into the temp variable.
        int temp;
        fscanf(fileptr, "%d ", &temp);
        // insert temp into the linked list.
        push(head, temp);
    }
    // close the file pointer
    fclose(fileptr);

    // print the stack.
    printf("Stack: ");
    printStack(head);

    // pop elements
    printf("\nPopping elements from the stack...\n");
    while (head->count)
    {
        printf("Element popped: %d\n", pop(head)->element);
    }
    printf("Element popped: %d\n", pop(head)->element);
}