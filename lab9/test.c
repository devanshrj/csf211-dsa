#include "parser.h"

int main() {
    char* file = "input.txt";
    int size;

    wchar_t** book = parser(file, &size);

    for (int i = 0; i < size; i++) {
        printf("%ls\n", book[i]);
    }
}