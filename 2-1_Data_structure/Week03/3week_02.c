#include <stdio.h>
#pragma warning(disable:4996)

int rPrintDigits(int N);

int main() {
	int n;
	scanf("%d", &n);
	rPrintDigits(n);
}

int rPrintDigits(int N) {
	if (N < 10)		printf("%d\n", N % 10);
	else  rPrintDigits(N / 10), printf("%d\n", N % 10);
}