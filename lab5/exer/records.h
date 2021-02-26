/* Header for records */

#include <stdio.h>
#include <stdlib.h>
#include "creditCard.h"

/* Procedure to read records from file "filename" into array card_arr */
CreditCard* readRecords(CreditCard* card_arr, char* filename, int* final_size);