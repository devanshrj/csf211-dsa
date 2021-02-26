/* Test procedures */

#include "records.h"
#include "measure.h"
#include "insertion.h"

void printR(CreditCard card) {
    printf("card no: %llu\n", card.card_no);
}

int main(int argc, char* argv[]) {
    // testing measurement procedures
    printf("Testing time measurement for sorting records...\n");
    insertionTime(argv[1], argv[2]);

    printf("\nTesting space measurement for sorting records...\n");
    insertionSpace(argv[1], argv[2]);
    printf("Done!\n");

    // testing insertion sort
    int size;
    CreditCard* card_arr;
    card_arr = readRecords(card_arr, argv[1], &size);

    insertionSort(card_arr, size);
    printf("Array sorted!\n");

    printf("Sorted array: \n");
    for (int i = 0; i < size; i++) {
        printR(card_arr[i]);
    }
}