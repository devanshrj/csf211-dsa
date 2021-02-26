/* Implementations of measurement functions */

#include "measure.h"

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