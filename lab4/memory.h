/* Header for Memory Allocation */

#include <stdio.h>
#include <stdlib.h>

/* procedure for memory allocation */
void* myalloc(int size);

/* procedure for memory deallocation */
void myfree(void *ptr);

/* print total size of heap stored in global variable */
void printSize();