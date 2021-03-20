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
    strcpy(output, "output/");
    strcat(output, argv[2]);

    FILE *fin = fopen(input, "r");
    FILE *fout = fopen(output, "w");

    int size = atoi(argv[1]);
    Employee arr[size];
    int i = 0;

    while(!feof(fin)){
        fscanf(fin, "%[^ ] %d\n", arr[i].name, &arr[i].empID);
        i++;
    }
    
    struct timeval t1, t2;

    gettimeofday(&t1, 0);
    // sorting procedure
    int cutoff = estimateCutoff(arr, size);

    hybridSort(arr, size, cutoff);

    // sorting procedure ends
    gettimeofday(&t2, 0);

    double time = (t2.tv_usec - t1.tv_usec) / 1000.0;

    fprintf(fout, "Time taken for size %d with cutoff %d: %f", size, cutoff, time);
    fprintf(fout, "\nSorted:\n");
    for(int i = 0; i < size; i++) {
		fprintf(fout, "%s %d\n", arr[i].name, arr[i].empID);
	}

    fclose(fin);
    fclose(fout);
}