#include <stdio.h>
#pragma warning (disable:4996)

int sum(int n);

int main() {
    int N, res = 0;
    scanf("%d", &N);

    for (int j = 1; j <= N; j++)
        res += sum(j);

    printf("%d", res);
    return 0;
}

int sum(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++)
        sum += i;
    return sum;
}