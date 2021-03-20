#include <stdio.h>

#include "estimateCutoff.h"
#include "hybridSort.h"
#include "insertionSort.h"
#include "quickSort.h"
#include "testRun.h"

int main() {
    Employee arr[10];
	arr[0].empID = 2;
	arr[1].empID = 3;
	arr[2].empID = 6;
	arr[3].empID = 10;
	arr[4].empID = 5;
	arr[5].empID = 4;
	arr[6].empID = 3;
	arr[7].empID = 2;
	arr[8].empID = 1;
	arr[9].empID = 33;

	/* exer_1 test
    printf("Initial:\n");
	for(int i=0;i<10;i++){
		printf("%d ",arr[i].empID);
	}

    insertionSort(arr, 10);
	quickSort(arr, 10, 0);
	hybridSort(arr, 10, 3);

    printf("\nSorted:\n");
    for(int i=0;i<10;i++){
		printf("%d ",arr[i].empID);
	}
	*/

	/* testRun test
	double *time = testRun(arr, 10);
    printf("Time for insertion sort: %f\n", time[0]);
    printf("Time for quick sort: %f\n", time[1]);
	*/

	// /* estimateCutoff test
	int cutoff = estimateCutoff(arr, 10);
	printf("Cutoff for array of size %d: %d\n", 10, cutoff);
	// */
}