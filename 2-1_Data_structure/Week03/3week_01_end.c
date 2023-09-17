#include <stdio.h>
#pragma warning(disable:4996)

int sumx(int N);

int main() {
	int N;

	scanf("%d", &N);
	printf("%d", sumx(N));
}

int sumx(int N) {
	if (N == 1) return 1;
	return sumx(N - 1) + N;
}