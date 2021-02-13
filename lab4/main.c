/* Driver for Exercise 3-5 */

#include "cycle.h"

#define NUM 1000000

bool testCyclic(linkedList ls) {
    return true;
}

int main() {
    // create lists
    linkedList ls = createList(NUM);
    linkedList cyclic = createCycle(ls);

    if (testCyclic(cyclic)) {
        printf("The linked list is cyclic!\n");
    }
}