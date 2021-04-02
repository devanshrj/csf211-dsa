#include "hashFunction.h"

int hashFunction(char* string, int baseNumber, int tableSize) {
    int myHash = 0;

    for (char c = s[0], int i = 0; c != '\0'; i++) {
        myHash += c;
        c = s[i];
    }

    return ((myHash % baseNumber) % tableSize);
}