/* Link-Reversal algorithm */

#include "cycle.h"

bool testCyclic (linkedList ls) {
    if (ls.count == 0 || ls.count == 1)
        return false;
    
    struct node *traverse = ls.first;
    struct node *previous = ls.first, *prevprev = NULL;

    // traverse the linkedlist
    while (traverse->next != NULL) {
        // link previous to prevprev
        if (previous != ls.first)
            previous->next = prevprev;

        // swap nodes
        prevprev = previous;
        previous = traverse;
        traverse = traverse->next;

        if (traverse == ls.first)
            return true;
    }
    return false;
}