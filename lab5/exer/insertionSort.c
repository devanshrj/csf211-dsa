/* Implementation of insertion procedures */

#include "insertion.h"

void insertInOrder(CreditCard* card_arr, CreditCard new_card, int n) {
    CreditCard card = new_card;
    CreditCard temp;

    // insertion sort comparisons
   int i = n - 2;
   while (i >= 0 && card_arr[i].card_no > card.card_no) {
       card_arr[i + 1] = card_arr[i];
        i--;
   }
   card_arr[i + 1] = card;
}

void insertionSort(CreditCard* card_arr, int n) {
    // edge case
    if (n == 0) {
        top_stack = &n;
        return;
    }
    
    insertionSort(card_arr, n - 1);
    insertInOrder(card_arr, card_arr[n - 1], n);
}