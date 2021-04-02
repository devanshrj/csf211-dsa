#include "hashFunction.h"

int hashFunction(wchar_t* string, int baseNumber, int tableSize) {
    int myHash = 0;

    for (int i = 0; i < wcslen(string); i++) {
        myHash += string[i];
        myHash %= baseNumber;
    }

    myHash %= tableSize;
    return myHash;
}