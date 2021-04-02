#include "profiler.h"

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

    printf("Best index for baseNumber: (%d, %d) = %d\n", best_i, best_j, collisions[best_i][best_j]);
    printf("Best index for tableSize: %d = %d\n", best_i, collisions[best_i][best_j]);
}