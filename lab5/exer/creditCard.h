/* Credit card struct */

#ifndef CREDIT_CARD
#define CREDIT_CARD

typedef struct {
    unsigned long long card_no;
    char bank_code[5];
    char expiry_date[6];
    char first_name[20];
    char last_name[20];
} CreditCard;

#endif