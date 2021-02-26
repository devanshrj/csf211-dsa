/* Read records implementation */

#include "readRecords.h"

CreditCard* readRecords(CreditCard* card_arr, char* filename, int* final_size) {
    int size = 5;

    // create a new card array
    // calloc instead of malloc for memory optimisation
    card_arr = (CreditCard *) calloc(size, sizeof(CreditCard));

    // open file
    FILE *fptr = fopen(filename, "r");
    if (fptr == NULL) {
        printf("Error! Unable to open file.");
        exit(0);
    }

    // i stores the number of records read
    int i = 0;
    CreditCard new;

    while (!feof(fptr)) {
        fscanf(fptr,"\"%llu,%[^,],%[^,],%[^,],%[^\"]\"\n",&(new.card_no), new.bank_code, new.expiry_date, new.first_name, new.last_name);
        card_arr[i++] = new;

        // check size of array, reallocate if necessary
        if (i == size) {
            size *= 2;
            card_arr = realloc(card_arr, sizeof(CreditCard) * size);
        }
    }

    fclose(fptr);

    // store final size of array = number of records read in final_size
    *final_size = i;

    return card_arr;
}