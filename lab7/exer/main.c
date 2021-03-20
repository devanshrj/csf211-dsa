#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

#include "estimateCutoff.h"
#include "hybridSort.h"

int main(int argc, char *argv[]) {
    char input[20], output[20];
    strcpy(input, "input/");
    strcat(input, argv[1]);

    FILE *fin = fopen(input, "r");
    FILE *res = fopen("results.txt", "a");

    int size = atoi(argv[1]);
    Employee arr[size];
    int i = 0;

    while(!feof(fin)){
        fscanf(fin, "%[^ ] %d\n", arr[i].name, &arr[i].empID);
        i++;
    }
    
    struct timeval t1, t2;

    int cutoff = estimateCutoff(arr, size);

    // sorting procedure
    gettimeofday(&t1, 0);
    hybridSort(arr, size, cutoff);
    gettimeofday(&t2, 0);

    double time = (t2.tv_usec - t1.tv_usec) / 1000.0;

    fprintf(res, "Time taken for size %d with cutoff %d: %f\n", size, cutoff, time);

    fclose(fin);
    fclose(res);
}