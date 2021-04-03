#include "parser.h"

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