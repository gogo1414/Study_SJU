#include <stdio.h>
#pragma warning(disable:4996)

int ABC(int n[], int k);

int main() {
    int x[10] = { 0, }, i, j, tmp = 0;
    for (i = 0; i < 10; i++)
        scanf("%d", &x[i]);

    for (i = 0; i < 10; i++) 
        ABC(x, i);
    
    for (i = 0; i < 10; i++)
        printf(" %d", x[i]);

    return 0;
}

int ABC(int n[], int k) {
    int j, size = 0, tmp = 0, max = n[k];
    for (j = k; j < 10; j++) {
        if (max < n[j]) {
            max = n[j];
            size = j;
        }
    }
    if (size != 0) {
        tmp = n[k];
        n[k] = max;
        n[size] = tmp;
    }
}
