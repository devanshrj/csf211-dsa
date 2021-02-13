/* Exercise 1: Stack space */

/* 
Stack space:
(a): Since the stack space is allocated only during the execution of the procedure and then deallocated, 
the same stack space is used for the variables of each procedure.

(b): Due to recursion, the calling method is not terminated till the base case. 
So, the variables stay allocated in the stack space.
As a result, a new location is given to the variable n after every recursive call of the procedure.
*/

#include <stdio.h>
#include <stdlib.h>

void p() {
    int pilani = 1;
    printf("\np: %u\n", &pilani);
}

void g() {
    int goa = 2;
    printf("\ng: %u\n", &goa);
}

void h() {
    int hyd = 1;
    printf("\nh: %u\n", &hyd);
}

void d() {
    int dub = 1;
    printf("\nd: %u\n", &dub);
}

void p_rec(int n) {
    printf("\nn: %d   p: %u\n", n, &n);
    if (n == 10)
        return ;
    else
        p_rec(n + 1);
}

int main() {
    printf("Procedures:\n");
    p();
    g();
    h();
    d();
    p_rec(1);
}