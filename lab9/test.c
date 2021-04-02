#include "collision.h"
#include "parser.h"
#include "profiler.h"

int main() {
    char* file = "test_input.txt";
    int size;

    wchar_t** book = parser(file, &size);

    // for (int i = 0; i < size; i++) {
    //     printf("%ls\n", book[i]);
    // }

    // int collisions = collisionCount(book, size, 17, 10);
    // printf("\nCollisions = %d\n", collisions);

    profiler(book, size);
}