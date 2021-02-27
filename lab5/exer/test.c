/* Test procedures */

#include "readRecords.h"
#include "measureTimeAndSpace.h"
#include "insertionSort.h"

void printR(CreditCard card) {
    // printf("card no: %llu;    code: %s;    expiry: %s;    fname: %s;    lname:%s\n", card.card_no, card.bank_code, card.expiry_date, card.first_name, card.last_name);
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

    printf("Initial array: \n");
    for (int i = 0; i < size; i++) {
        printR(card_arr[i]);
    }

    printf("\nSorting array...\n");
    insertionSort(card_arr, size);
    printf("Array sorted!\n");

    printf("\nSorted array: \n");
    for (int i = 0; i < size; i++) {
        printR(card_arr[i]);
    }
}