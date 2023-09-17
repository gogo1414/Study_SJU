#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int sumx(int N, int res);

int main() {
	int N, res = 0;

	scanf("%d", &N);
	printf("%d", sumx(N, res));
}

int sumx(int N, int res) {
	res += N;
	if (N - 1 == 0)
		return res;
	sumx(N - 1, res);
}