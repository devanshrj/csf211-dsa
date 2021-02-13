/* Exercise 2: Heap space */

#include "memory.h"

/* 
(c) Heap space is used to dynamically allocate memory using malloc().
malloc() returns NULL pointer when allocation fails.
*/

// global variable to keep track of space allocated
long long totalSize = 0;

void* myalloc(int size) {
    totalSize += size;
    
    // allocating space for one more element to store size
    int *ptr = malloc(size + sizeof(int));

    if (ptr == NULL)
        return (void *) ptr;
    
    // store size required at index 0
    ptr[0] = size;
    ptr++;

    return (void *) ptr;
}

void myfree(void *ptr) {
    // retrieve size stored in index 0
    int *temp = (int *) ptr;
    temp--;
    totalSize -= *temp;

    free(temp);
}

void printSize() {
    printf("Size of heap: %lld\n", totalSize);
}

void testMemory() {
    int *arr, M;
    int upper = 25000, lower = 10000;

    while (1) {
        // to generate random number in the range [10000, 25000]
        M = (rand() % (upper - lower + 1)) + lower;
        arr = (int *) myalloc(sizeof(int) * M);
        printf("First address: %p       Last address: %p\n     Heap: %lld\n", arr, arr + M, totalSize);

        // If the below line is commented, the loop executes till the RAM memory is completely filled and then terminates.
        // Else, the memory allocated in the iteration is freed and used again for the next iteration.
        myfree(arr);
    }
}