/* Driver for Exercise 3-5 */

#include "cycle.h"
#include <sys/time.h>

#define NUM 1000000

// global variable for heap space, used from memory.c
extern long long totalSize;

int getCycle(linkedList ls) {
    struct node *hare, *tort;
    hare = tort = ls.first;

    while (hare->next != NULL && hare->next->next != NULL) {
        hare = hare->next->next;
        tort = tort->next;
        
        if (hare == tort)
            break;
    }
    
    int start = 0;
    tort = ls.first;
    while (tort != hare) {
        tort = tort->next;
        start++;
    }
    return start;
}

linkedList makeCircular(linkedList ls) {
    struct node *ptr = ls.first;

    // if linear list, point last node to first node
    if (!testCyclic(ls)) {
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = ls.first;
        return ls;
    }

    // if cyclic list, free nodes before cycle
    // use hare-tortoise algorithm to get the starting node of cycle
    int start = getCycle(ls);
    struct node *temp = NULL;
    for (int i = 0; i < start; i++) {
        temp = ptr;
        ptr = ptr->next;
        myfree(temp);
    }

    ls.first = ptr;
    ls.count -= start;
    return ls;
}

int main() {
    // create lists
    linkedList ls = createList(NUM);

    FILE *fptr = fopen("heap.txt", "w");
    fprintf(fptr, "Number of elements: %d\n", NUM);
    fprintf(fptr, "Heap space used by createList(): %lld\n", totalSize);
    FILE *csv = fopen("observations.csv", "a");

    ls = createCycle(ls);

    struct timeval t1, t2;
	double elapsedTime;
	gettimeofday(&t1, NULL);

	int isCyclic = testCyclic(ls);

	gettimeofday(&t2, NULL);

	// compute and print the elapsed time in millisec
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
	fprintf(fptr, "\nTotal time for detection of cyclic is %f ms.\n", elapsedTime);

	if (isCyclic) {
		fprintf(fptr, "Detected Cyclic.\n");
	}
	else {
		fprintf(fptr, "Detected Linear.\n");
	}

    ls = makeCircular(ls);
    fprintf(fptr,"\nHeap space after makeCircular(): %lld\n", totalSize);
	fclose(fptr);

    // fprintf(csv, "%d, %f, %lld\n", NUM, elapsedTime, totalSize);
    // fclose(csv);
}