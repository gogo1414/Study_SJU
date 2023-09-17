#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

/* 제자리 삽입 정렬 (의사코드 노참조 버전) 
   해당 버전의 코드는 주석처리             */

/* 제자리 삽입 정렬 (의사코드 참조 버전) */

void swapElement_InsertSort(int*, int);

int main() {
	int n, *arr;

	// 배열 크기 입력
	scanf("%d", &n);

	// 배열 크기 n 할당
	arr = (int*)malloc(sizeof(int) * n);

	if (arr == NULL) {
		printf("메모리 부족");
		return 0;
	}

	for (int i = 0; i < n; i++)
		scanf("%d", arr + i);

	swapElement_InsertSort(arr, n);

	for (int i = 0; i < n; i++)
		printf(" %d", *(arr + i));
	
	// 메모리 할당 해제
	free(arr);

	return 0;
}

// 제자리 삽입정렬 (의사코드 참조)
void swapElement_InsertSort(int* arr, int n) {
	int min, j;

	for (int i = 1; i < n; i++) {
		min = *(arr+i);
		j = i - 1;           
		while ((j >= 0) && (*(arr + j) > min)) {
			*(arr + j + 1) = *(arr + j);
			j = j - 1;
		}
		*(arr + j + 1) = min;
	}

	return;
}

/* 제자리 삽입정렬(의사코드 노참조)
void swapElement_InsertSort(int* arr, int n) {
	int tmp, num, min;

	for (int i = 0; i < n - 1; i++) {
		min = *(arr + n - 1);
		num = n-1;
		for (int j = n-1; j >= i; j--) {
			if (min > *(arr + j)) {
				min = *(arr + j);
				num = j;
			}
		}
		tmp = *(arr + i);
		*(arr + i) = min;
		*(arr + num) = tmp;
	}

	return;
}*/