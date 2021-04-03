#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

/* 
Exercise 1 
*/

int hashFunction(wchar_t* string, int baseNumber, int tableSize) {
    int myHash = 0;

    for (int i = 0; i < wcslen(string); i++) {
        myHash += string[i];
        myHash %= baseNumber;
    }

    myHash %= tableSize;
    return myHash;
}

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

wchar_t **parser(char *fileName, int *size) {
    wchar_t **book = NULL;
    FILE *finp = fopen(fileName, "r");

    printf("Parsing the input file...\n");

    int currentSize = 10;
    book = (wchar_t **) malloc(sizeof(wchar_t *) * currentSize);

    int valid = 0;
    wchar_t currentString[10000] = { 0 };

    while (fwscanf(finp, L"%ls ", currentString) != EOF) {
        book[valid] = (wchar_t *) malloc(sizeof(wchar_t) * (wcslen(currentString) + 1));
        wcscpy(book[valid], currentString);
        valid++;

        if (valid >= currentSize) {
            currentSize *= 2;
            book = (wchar_t **) realloc(book, sizeof(wchar_t *) * currentSize);
        }
    }

    *size = valid;
    printf("Number of valid strings: %d\n", valid);
    fclose(finp);

    return book;
}

void profiler(wchar_t **book, int size) {
    int baseNumber[][6] = {
        {5003, 5009, 5011, 5000011, 5000077, 5000081}, 
        {50021, 50023, 50033, 50000017, 50000021, 50000047}, 
        {500009, 500029, 500041, 500000003, 500000009, 500000041}
        },
        tableSize[] = { 5000, 50000, 500000 };

    int collisions[3][6], best_i = 0, best_j = 0;

    printf("\nExecuting profiler...\n");

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 6; j++) {
            collisions[i][j] = collisionCount(book, size, baseNumber[i][j], tableSize[i]);
            printf("Collisions for tableSize = %d, baseNumber = %d: %d\n", tableSize[i], baseNumber[i][j], collisions[i][j]);
            
            if (collisions[best_i][best_j] > collisions[i][j]) {
                best_i = i;
                best_j = j;
            }
        }
    }

    printf("Best index for baseNumber: (%d, %d) = %d\n", best_i, best_j, baseNumber[best_i][best_j]);
    printf("Best index for tableSize: %d = %d\n", best_i, tableSize[best_i]);
}


/*
Exercise 2
*/

/* struct definitions */
typedef struct node Node;
struct node {
    int firstIndex;
    int count;
    Node *next;
};

typedef struct hashtable HashTable;
struct hashtable {
    int tableSize;
    int baseNumber;
    Node **table;
    
    int elementCount;
    int insertionCost;
    int queryingCost;
};

/* functions */
Node* newNode() {
    Node *new = malloc(sizeof(Node));
    new->firstIndex = 0;
    new->count = 0;
    new->next = NULL;
    return new;
}

HashTable* newHashTable(int tableSize, int baseNumber) {
    HashTable *newTable = malloc(sizeof(HashTable));
    newTable->tableSize = tableSize;
    newTable->baseNumber = baseNumber;
    
    newTable->table = malloc(sizeof(Node *) * tableSize);
    for (int i = 0; i < tableSize; i++) {
        newTable->table[i] = NULL;
    }

    newTable->elementCount = 0;
    newTable->insertionCost = 0;
    newTable->queryingCost = 0;
    return newTable;
}

void insert(wchar_t **book, int index, HashTable *myHash) {
    int theHash = hashFunction(book[index], myHash->baseNumber, myHash->tableSize);

    if (myHash->table[theHash] == NULL) {
        myHash->table[theHash] = newNode();
        myHash->table[theHash]->firstIndex = index;
        myHash->table[theHash]->count = 1;
        myHash->elementCount++;
    }
    else {
        Node *current = myHash->table[theHash];
        // next node is not null and current string is not input string
        while (current->next != NULL && wcscmp(book[index], book[current->firstIndex])) {
            myHash->insertionCost++;
            current = current->next;
        }
        // if strings are equal
        if (!(wcscmp(book[index], book[current->firstIndex]))) {
            current->count++;
        }
        else {
            current->next = newNode();
            current->next->firstIndex = index;
            current->next->count = 1;
            myHash->elementCount++;
        }
    }
}

int insertAll(wchar_t **book, int size, HashTable *myHash) {
    for (int i = 0; i < size; i++) {
        insert(book, i, myHash);
    }
    return myHash->insertionCost;
}

Node* lookup(wchar_t **book, int index, HashTable *myHash) {
    int theHash = hashFunction(book[index], myHash->baseNumber, myHash->tableSize);

    Node *current = myHash->table[theHash];
    while (current && wcscmp(book[index], book[current->firstIndex])) {
        myHash->queryingCost++;
        current = current->next;
    }

    return current;
}

int lookupAll(wchar_t **book, int size, HashTable *myHash, double m) {
    myHash->queryingCost = 0;

    for (int i = 0; i < (int)(size * m); i++) {
        lookup(book, i % (size - 1), myHash);
    }

    return myHash->queryingCost;
}


/*
Exercise 3
*/

double lookupProfile(wchar_t **book, int size, HashTable *myHash) {
    for (double m = 0; m < 2.0; m += 0.1) {
        if (lookupAll(book, size, myHash, m) > myHash->insertionCost)
            return m;
    }
    return 2.0;
}


/*
driver: main()
*/

int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "en_US.UTF-8");

    if (argc != 2) {
        printf("Invalid number of arguments!\n");
        return -1;
    }

    int size;
    wchar_t **book = parser(argv[1], &size);

    printf("\nExecuting hash table operations...\n");

    // hardcoded tableSize = 50000, baseNumber = 50021, collisions = 28066
    HashTable *myHash = newHashTable(50000, 50021);
    printf("Total Insertion Cost: %d\n", insertAll(book, size, myHash));
    printf("Element Count: %d\n", myHash->elementCount);
    printf("Total Querying Cost: %d\n", lookupAll(book, size, myHash, 1));

    printf("\nExecuting lookup profile...\n");
    printf("Value of m required: %f\n", lookupProfile(book, size, myHash));
}