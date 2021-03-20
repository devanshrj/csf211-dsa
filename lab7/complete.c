#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

// Employee struct
typedef struct {
	char name[11];
	int empID;
} Employee;

// insertionSort
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

// quickSort
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

// hybridSort
void hybridSort(Employee *arr, int size, int S) {
    quickSort(arr, size, S);
    insertionSort(arr, size);
}

// testRun
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

// estimateCutoff
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

// main
int main(int argc, char *argv[]) {
    char input[20], output[20];
    strcpy(input, "input/");
    strcat(input, argv[1]);

    FILE *fin = fopen(input, "r");
    FILE *fout = fopen(argv[2], "w");
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

    for(int j = 0; j < size; j++) {
        fprintf(fout, "%s %d\n", arr[j].name, arr[j].empID);
    }

    fclose(fin);
    fclose(fout);
    fclose(res);
}