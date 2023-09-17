#include <stdio.h>
#include <stdlib.h> // rand() 포함.
#include <Windows.h> // 작업 시간 측정 헤더파일
#include <time.h> // 시간 헤더파일
#pragma warning(disable:4996)

void inputElement_Array(int*, int*, int);
void swapElement_insertionSort(int*, int);
void swapElement_selectionSort(int*, int);
void print_Array(int*, int);
boolean empty_Array(int*);

int main() {
	int n, *A, *B;
	
	// 작업시간측정
	LARGE_INTEGER ticksPerSec1, ticksPerSec2;
	LARGE_INTEGER start1, end1, start2, end2, diff1, diff2;

	srand(time(NULL));

	scanf("%d", &n);

	A = (int*)malloc(n * sizeof(int));
	B = (int*)malloc(n * sizeof(int));

	// 메모리 할당 확인
	if (A == NULL || B == NULL) {
		printf("메모리가 충분하지 않습니다!");
		return 0;
	}

	inputElement_Array(A, B, n);

	// 선택정렬 작업 시간 측정
	QueryPerformanceFrequency(&ticksPerSec1);
	QueryPerformanceCounter(&start1);
	swapElement_selectionSort(A, n);
	QueryPerformanceCounter(&end1);

	diff1.QuadPart = end1.QuadPart - start1.QuadPart;
	printf("%.9fms\n", ((double)diff1.QuadPart / (double)ticksPerSec1.QuadPart) * (double) 1000);

	// 삽입 정렬 작업 시간 측정
	QueryPerformanceFrequency(&ticksPerSec2);
	QueryPerformanceCounter(&start2);
	swapElement_insertionSort(B, n);
	QueryPerformanceCounter(&end2);
	diff2.QuadPart = end2.QuadPart - start2.QuadPart;
	printf("%.9fms\n", ((double)diff2.QuadPart / (double)ticksPerSec2.QuadPart) * (double) 1000);
	
	return 0;
}

void print_Array(int* A, int n) {
	for (int i = 0; i < n; i++)
		printf(" %d", A[i]);
	printf("\n");
}

void inputElement_Array(int* A, int* B, int n) {
	for (int i = 0; i < n; i++) {
		A[i] = rand() % 30000 + 1;
		B[i] = rand() % 30000 + 1;
	}
	return;
}

void swapElement_selectionSort(int* A, int n) {
	int max, tmp;
	for (int i = n-1; i > 0; i--) {
		max = i;
		for (int j = i-1; j >= 0; j--) {
			if (A[max] < A[j])
				max = j;
		}
		tmp = A[i];
		A[i] = A[max];
		A[max] = tmp;
	}
	return;
}

void swapElement_insertionSort(int* B, int n) {
	int min, j;
	for (int i = 1; i < n; i++) {
		min = B[i];
		j = i - 1;
		while ((j >= 0) && (B[j] > min)) {
			B[j + 1] = B[j];
			j -= 1;
		}
		B[j + 1] = min;
	}
	return;
}