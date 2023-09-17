#include <stdio.h>
#pragma warning(disable:4996)

int swap(int* p, int* o);

int main() {
    int x[50] = { 0, }, i, N, * p = x, * o = x, a1, a2;
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%d", &x[i]);
    }
    scanf("%d %d", &a1, &a2);

    p = x + a1;
    o = x + a2;

    swap(p, o);

    for (i = 0; i < N; i++) 
        printf(" %d", x[i]);
    
    return 0;
}

int swap(int* p, int* o) {
    int tmp = 0;
    tmp = *p;
    *p = *o;
    *o = tmp;
}