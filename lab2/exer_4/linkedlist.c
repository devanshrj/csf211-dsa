/* Linked List operations */

#include "linkedlist.h"
#include <stdlib.h>

void insertFirst(struct linkedList *head, int ele)
{
	// create a node
	struct node *link = (struct node *)malloc(sizeof(struct node));
	// creating a node whose address is being stored in the link pointer.

	link->element = ele;

	// point it to old first node
	link->next = head->first;
	// point first to new first node
	head->first = link;
	head->count++;
}

struct node *deleteFirst(struct linkedList *head)
{
	// temporary link
	if (!head->count) {
		printf("List empty!\n");
        return NULL;
	}

	struct node *temp = (struct node *)malloc(sizeof(struct node));

	temp = head->first;
	// point first to temp's next
	head->first = temp->next;
	head->count--;

	return temp;
}

void printList(struct linkedList *head)
{
	struct node *ptr = head->first;
	printf("\n[ ");
	// start from the beginning
	while (ptr != NULL)
	{
		printf("%d, ", ptr->element);
		ptr = ptr->next;
	}
	printf("]\n");
}

void printToFile(struct linkedList *head, FILE *fptr)
{
	struct node *ptr = head->first;
	fprintf(fptr, "\n[ ");
	// start from the beginning
	while (ptr != NULL)
	{
		fprintf(fptr, "%d, ", ptr->element);
		ptr = ptr->next;
	}
	fprintf(fptr, "]\n");
}

int search(struct linkedList *head, int ele)
{
	struct node *ptr = head->first;
	while (ptr != NULL)
	{
		if (ptr->element == ele)
			return 1;
		ptr = ptr->next;
	}
	return 0;
}

struct node *delete (struct linkedList *head, int ele)
{
	if (!head->count) {
		printf("Stack empty!\n");
        return NULL;
	}

	struct node *ptr = head->first;
	struct node *temp = (struct node *)malloc(sizeof(struct node));

	if (ptr->element == ele) {
		head->first = ptr->next;
		return ptr;
	}
	
	while (ptr->next != NULL)
	{
		if ((ptr->next)->element == ele)
		{
			temp = ptr->next;
			ptr->next = temp->next;
			return temp;
		}
		ptr = ptr->next;
	}
	printf("Element %d not found!\n", ele);
	return NULL;
}
