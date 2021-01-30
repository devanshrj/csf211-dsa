/* Driver for Linked List */

#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Create a file pointer and open the file read as command line argument.
    FILE *fileptr = fopen(argv[1], "r");

    // Declare a pointer to a linked list (head) and allocate memory to it.
    struct linkedList *head =
        (struct linkedList *)malloc(sizeof(struct linkedList));
    head->first = NULL;
    head->count = 0;

    // list insertion
    // In a loop read the file and insert elements into the linkedList.
    while (!feof(fileptr))
    {
        // read the next element and store into the temp variable.
        int temp;
        fscanf(fileptr, "%d ", &temp);
        // insert temp into the linked list.
        insertFirst(head, temp);
    }
    // close the file pointer
    fclose(fileptr);

    // print the linked list.
    printf("List: ");
    printList(head);

    // delete the first element of the linked list.
    printf("\nDelete first: ");
    deleteFirst(head);
    printList(head);

    // print the linked list to a new file.
    /* FILE *fout = fopen(argv[2], "w"); */
    /* printToFile(head, fout); */

    // search operation
    printf("\nSearch element 9:\n");
    printf("Element found? %d\n", search(head, 9));

    // delete operation
    printf("\nDelete element 9: ");
    delete (head, 9);

    printList(head);
}