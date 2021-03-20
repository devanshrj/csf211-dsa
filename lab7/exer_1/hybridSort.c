#include "hybridSort.h"

void hybridSort(Employee *arr, int size, int S) {
    quickSort(arr, size, S);
    insertionSort(arr, size);
}