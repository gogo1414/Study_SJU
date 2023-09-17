#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#pragma warning(disable:4996)

int* prefixAverages1(int* X, int n);
int* prefixAverages2(int* X, int n);

int main() {
	LARGE_INTEGER tickspersec;
	LARGE_INTEGER start, end, diff;
	int* A, * res1, * res2, n;
	srand(time(NULL));
	scanf("%d", &n);
	A = (int*)malloc(sizeof(int) * n);
	res1 = (int*)malloc(sizeof(int) * n);
	res2 = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		A[i] = rand() % 10001;
	QueryPerformanceFrequency(&tickspersec);
	QueryPerformanceCounter(&start);
	res1 = prefixAverages1(A, n);
	QueryPerformanceCounter(&end);
	diff.QuadPart = end.QuadPart - start.QuadPart;
	printf("1. %.10f\n", (double)diff.QuadPart / (double)tickspersec.QuadPart);


	QueryPerformanceCounter(&start);
	res2 = prefixAverages2(A, n);
	QueryPerformanceCounter(&end);
	diff.QuadPart = end.QuadPart - start.QuadPart;
	printf("2. %.10f\n", (double)diff.QuadPart / (double)tickspersec.QuadPart);

	return 0;
}

int* prefixAverages1(int* X, int n) {
	int* A, i, j, sum;
	A = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++) {
		sum = 0;
		for (j = 0; j <= i; j++) {
			sum += X[j];
		}
		A[i] = (sum / (double)(i + 1)) + 0.5;
	}
	return A;
}

int* prefixAverages2(int* X, int n) {
	int* A, i, j, sum = 0;
	A = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++) {
		sum += X[i];
		A[i] = (sum / (double)(i + 1)) + 0.5;
	}
	return A;
}