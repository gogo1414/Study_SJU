#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)


int main() {
    int N, i, j;
    int** arr = (int**)malloc(sizeof(int*) * 2);
    scanf("%d", &N);

    for (i = 0; i < 2; i++)
        *(arr + i) = (int*)malloc(sizeof(int) * N);

    for (i = 0; i < 2; i++) {
        for (j = 0; j < N; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    for (i = 0; i < N; i++) {
        printf(" %d", arr[0][i] + arr[1][N - 1 - i]);
    }

    return 0;
}
