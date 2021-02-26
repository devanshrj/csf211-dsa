/* Header for measurement functions */

#include <string.h>
#include <sys/time.h>
#include "readRecords.h"
#include "insertionSort.h"

/* Procedure for measuring the time taken to read records from file "filename" */
void recordTime(char* filename, char* output);

/* Procedure for measuring the time taken to perform insertion sort on records from file "filename" */
void insertionTime(char* filename, char* output);

/* Procedure for measuring the space taken to perform insertion sort on records from file "filename" */
void insertionSpace(char* filename, char* output);

/* Procedure for measuring the time and space taken to perform insertion sort for multiple input files */
void insertComp(int n);