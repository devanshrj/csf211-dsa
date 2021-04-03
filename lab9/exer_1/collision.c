#include "collision.h"

int collisionCount(wchar_t **array, int len, int baseNumber, int tableSize) {
    int collisions = 0, hash;

    int *hashes = (int *) calloc(tableSize, sizeof(int));

    // increase the value of index hash in hashes (represents hash table) by 1
    for (int i = 0; i < len; i++) {
        // check if string is unique
        int unique = 1;
        for (int j = 0; j < i - 1; j++) {
            if (!wcscmp(array[i], array[j]))
                unique = 0;
        }
        if (!unique)
            continue;
        
        hash = hashFunction(array[i], baseNumber, tableSize);
        hashes[hash]++;

        if (hashes[hash] > 1)
            collisions++;
    }
    
    return collisions;
}