/* Driver for Queue */

#include "./que.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    // Create a file pointer and open the file read as command line argument.
    FILE *fileptr = fopen(argv[1], "r");

    // Declare a pointer to a stack (top) and allocate memory to it.
    struct Queue *q = newQ();
    
    // stack insertion
    while (!feof(fileptr))
    {
        // read the next element and store into the temp variable.
        Element temp;
        fscanf(fileptr, "%d ", &temp);
        // printf("Element: %d\n", temp);
        // insert temp into the linked list.
        addQ(q, temp);
    }
    // close the file pointer
    fclose(fileptr);

    // print the stack.
    printf("Queue count: %d", lengthQ(q));
    printQ(q);

    // pop elements
    printf("\nRemoving elements from the queue...\n");
    while (q->count)
    {
        printf("Element popped: %d\n", front(q));
        q = delQ(q);
    }
    // printf("Element popped: %d\n", front(q));
}