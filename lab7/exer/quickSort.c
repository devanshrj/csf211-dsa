#include "quickSort.h"

void quickSortIterative(Employee *arr, int l, int h, int S);

void quickSort(Employee *arr, int size, int S) {
    quickSortIterative(arr, 0, size-1, S);
}

void swap(Employee *a, Employee *b) {
    // utility function to swap two elements of arr
    Employee temp = *a;
    *a = *b;
    *b = temp;
}

int partition(Employee *arr, int l, int h, int S) {
    if (h - l + 1 <= S) {
        return h;
    }

    int x = arr[h].empID;
    int i = l - 1;

    for (int j = l; j < h; j++) {
        if (arr[j].empID <= x) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[h]);
    return i + 1;
}

void quickSortIterative(Employee *arr, int l, int h, int S) {
    int stack[h - l + 1];
    int top = -1;

    // push initial values to stack
    stack[++top] = l;
    stack[++top] = h;

    // pop from stack while stack is not empty
    while (top >= 0) {
        h = stack[top--];
        l = stack[top--];

        // set pivot element at the right position using partition
        int p = partition(arr, l, h, S);

        // elements to left side of p
        if (p - 1 > l) {
            stack[++top] = l;
            stack[++top] = p - 1;
        }

        // elements to right side of p
        if (p + 1 < h) {
            stack[++top] = p + 1;
            stack[++top] = h;
        }
    }
}