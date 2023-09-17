#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int prefixAverages1(int* X, int n);
int prefixAverages2(int* X, int n);

int main() {
	int* A, * res1, * res2, n;
	scanf("%d", &n);
	A = (int*)malloc(sizeof(int) * n);
	res1 = (int*)malloc(sizeof(int) * n);
	res2 = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		scanf("%d", &A[i]);
	res1 = prefixAverages1(A, n);
	res2 = prefixAverages2(A, n);

	for (int i = 0; i < n; i++)
		printf("%d ", res1[i]);
	printf("\n");
	for (int i = 0; i < n; i++)
		printf("%d ", res2[i]);

	return 0;
}

int prefixAverages1(int* X, int n) {
	int* A, i, j, sum;
	A = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++) {
		sum = 0;
		for (j = 0; j <= i; j++) {
			sum += X[j];
		}
		A[i] = sum / (i + 1);
	}
	return A;
}

int prefixAverages2(int* X, int n) {
	int* A, i, j, sum = 0;
	A = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++) {
		sum += X[i];
		A[i] = sum / (i + 1);
	}
	return A;
}