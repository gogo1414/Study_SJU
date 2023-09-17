#include <stdio.h>
#pragma warning(disable:4996)

int rPrintDigits(int N);

int main() {
	int n;
	scanf("%d", &n);
	rPrintDigits(n);
}

int rPrintDigits(int N) {
	if ((N / 10) == 0)		printf("%d", N%10);
	else  printf("%d\n", N % 10), rPrintDigits(N/10);
}