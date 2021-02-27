/* Credit card struct */

#ifndef CREDIT_CARD
#define CREDIT_CARD

typedef struct {
    unsigned long long card_no;
    char bank_code[6];
    char expiry_date[8];
    char first_name[6];
    char last_name[6];
} CreditCard;

#endif