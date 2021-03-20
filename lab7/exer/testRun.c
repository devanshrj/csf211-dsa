#include <sys/time.h>
#include <stdlib.h>

#include "testRun.h"

double *testRun(Employee *Ls, int size) {
    double *time = (double *) malloc(sizeof(double) * 2);

    Employee arr1[size], arr2[size];
    for (int i = 0; i < size; i++) {
        arr1[i] = Ls[i];
        arr2[i] = Ls[i];
    }

    struct timeval t1, t2;
	double elapsedTime;

	gettimeofday(&t1, NULL);
	insertionSort(arr1, size);
	gettimeofday(&t2, NULL);
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
    time[0] = elapsedTime;

    gettimeofday(&t1, NULL);
	quickSort(arr2, size, 0);
	gettimeofday(&t2, NULL);
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
    time[1] = elapsedTime;

    return time;
}