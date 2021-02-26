/* Header for insertion procedures */

#include "creditCard.h"

/* Global variable to store top of stack */
int* top_stack;

/* Inserts a new credit card record in card_arr */
void insertInOrder(CreditCard* card_arr, CreditCard new_card, int n);

/* Recursive procedure that implements Insertion Sort */
void insertionSort(CreditCard* card_arr, int n);