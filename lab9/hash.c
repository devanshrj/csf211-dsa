#include <stdio.h>
#include <stdlib.h>

int hashFunction(char* string, int baseNumber, int tableSize) {
    int myHash = 0;

    for (char c = s[0], int i = 0; c != '\0'; i++) {
        myHash += c;
        c = s[i];
    }

    return ((myHash % baseNumber) % tableSize);
}

int collisionCount(char* array[], int len, int baseNumber, int tableSize) {
    int collisions = 0, hash;

    int *hashes = (int *) calloc(tableSize, sizeof(int));

    // increase the value of index hash in hashes (represents hash table) by 1
    for (int i = 0; i < len; i++) {
        hash = hashFunction(array[i], baseNumber, tableSize);
        hashes[hash]++;

        if (hashes[hash] > 1)
            collisions++;
    }
    
    return collisions;
}