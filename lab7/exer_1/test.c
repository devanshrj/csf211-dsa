#include <stdio.h>

#include "insertionSort.h"

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

    printf("Initial:\n");
	for(int i=0;i<10;i++){
		printf("%d ",arr[i].empID);
	}

    insertionSort(arr, 10);

    printf("\nSorted:\n");
    for(int i=0;i<10;i++){
		printf("%d ",arr[i].empID);
	}
}