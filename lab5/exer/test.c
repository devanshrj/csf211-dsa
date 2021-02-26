/* Test procedures */

#include "records.h"
#include "measure.h"

int main(int argc, char* argv[]) {
    printf("Testing time measurement for reading records...\n");
    recordTime(argv[1], argv[2]);
    printf("Done!\n");
}