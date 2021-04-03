/* Implementation of merge procedure */

#include "merge.h"

void merge(Element Ls1[], int sz1, Element Ls2[], int sz2, Element Ls[]) {
    int i = 0, j = 0, k = 0;
    
    while (i < sz1 && j < sz2) {
        if (Ls1[i].cgpa <= Ls2[j].cgpa) {
            Ls[k] = Ls1[i];
            i++, k++;
        }
        else {
            Ls[k] = Ls2[j];
            j++, k++;
        }
    }

    // copy remaining items from Ls1 to Ls
    while (i < sz1) {
        Ls[k] = Ls1[i];
        i++, k++;
    }

    // copy remaining items from Ls2 to Ls
    while (j < sz2) {
        Ls[k] = Ls2[j];
        j++, k++;
    }
}