#include <assert.h>
#include <stdio.h>
#include "estimateCutoff.h"

double diff(double a, double b) {
    return a - b > 0 ? a - b : b - a;
}

int estimateCutoff(Employee *Ls, int size) {
    // tt[0] -> IS time, tt[1] -> QS time
    double *tt;

    int min = 0, max = size;
    int mid;
    
    do {
        mid = (min + max) / 2;
        tt = testRun(Ls, mid);
        
        if (tt[0] < tt[1])
            min = mid;
        else
            max = mid;
    } while (diff(tt[0], tt[1]) > 0.1);

    return mid;
}