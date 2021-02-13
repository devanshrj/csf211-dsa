/* Hare and Tortoise algorithm */

#include "cycle.h"

bool testCyclic (linkedList ls) {
    if (ls.count == 0 || ls.count == 1)
        return false;
    
    struct node *hare, *tort;
    hare = tort = ls.first;

    while (hare->next != NULL && hare->next->next != NULL) {
        hare = hare->next->next;
        tort = tort->next;
        
        if (hare == tort)
            return true;
    }
    return false;
}