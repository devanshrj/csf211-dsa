/* Implementations of measurement functions */

#include "measureTimeAndSpace.h"

void insertComp() {
    // filenames for measurement outputs
    char* read = "readTime.txt";
    char* time = "insertionTime.txt";
    char* space = "insertionSpace.txt";

    // input files
    char input[15];
    const char check_str[9][7] = { "10", "100", "1000", "5000", "10000", "25000", "50000", "75000", "100000" };

    for (int i = 0; i < 9; i++) {
        strcpy(input, "input/");
        strcat(input, check_str[i]);

        printf("Performing time and space measurements on input file %s...\n", input);
        recordTime(input, read);
        insertionTime(input, time);
        insertionSpace(input, space);
    }
}

void recordTime(char* filename, char* output) {
    int size;
    CreditCard* card_arr;
    FILE *f = fopen(output, "a");

    struct timeval t1, t2;
	double elapsedTime;
	gettimeofday(&t1, NULL);
	card_arr = readRecords(card_arr, filename, &size);
	gettimeofday(&t2, NULL);

    // compute and print the elapsed time in millisec
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;

    fprintf(f, "Read %d records in %f ms.\n", size, elapsedTime);
    fclose(f);
}

void insertionTime(char* filename, char* output) {
    int size;
    CreditCard* card_arr;
    card_arr = readRecords(card_arr, filename, &size);

    FILE *f = fopen(output, "a");

    struct timeval t1, t2;
	double elapsedTime;
	gettimeofday(&t1, NULL);
	insertionSort(card_arr, size);
	gettimeofday(&t2, NULL);

    // compute and print the elapsed time in millisec
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;

    fprintf(f, "Sorted %d records in %f ms.\n", size, elapsedTime);
    fclose(f);
}

void insertionSpace(char* filename, char* output) {
    int size;
    int bottom_stack;
    CreditCard* card_arr;
    card_arr = readRecords(card_arr, filename, &size);

    FILE *f = fopen(output, "a");
    insertionSort(card_arr, size);

    fprintf(f, "Number of elements: %d;      Top of stack: %p;      Bottom of stack: %p;      Space used: %llu\n", 
    size, top_stack, &bottom_stack, (unsigned long long)&bottom_stack-(unsigned long long)top_stack);

    fclose(f);
}