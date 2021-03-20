#include "insertionSort.h"

void insertionSort(Employee *arr, int size) {
    for(int i = 1; i < size; i++) {
        Employee key = arr[i];

        int j = i - 1;
        while (j >= 0 && arr[j].empID > key.empID) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}