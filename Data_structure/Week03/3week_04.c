#include <stdio.h>
#pragma warning(disable:4996)

int rmaximum(int x[], int a);

int main() {
	int N, x[20] = { 0, }, max = 0;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d", &x[i]);

	printf("%d", rmaximum(x, max));

	return 0;
}

int rmaximum(int x[], int a) {
	if (*(x + 1) == 0)
		return a > *x ? a : *x;
	return a > *x ? rmaximum(x + 1, a) : rmaximum(x + 1, *x);
}