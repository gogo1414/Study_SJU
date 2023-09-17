#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

/* 제자리 선택정렬 (의사코드 미참조 버전) 
   해당 버전의 코드는 주석처리             */

/* 제자리 삽입정렬 (의사코드 참조 버전)  */
void swapElement_SelectionSort(int*, int);

int main() {
	int n, *arr;
	
	// 배열의 크기 입력
	scanf("%d", &n);
	
	// 배열에 크기 n 동적할당
	arr = (int*)malloc(n*sizeof(int));
	if (arr == NULL) {
		printf("메모리가 충분하지 않습니다!");
		return 0;
	}
	// 초기 상태 입력
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i);

	swapElement_SelectionSort(arr, n);

	for (int i = 0; i < n; i++)
		printf(" %d", *(arr + i));

	free(arr);

	return 0;
}

// 제자리 선택 정렬 알고리즘 의사코드 참조
void swapElement_SelectionSort(int* arr, int n) {
	int max, tmp;

	for (int i = n-1; i >= 1; i--) {
		max = i;
		for (int j = i-1; j >= 0; j--) {
			if (*(arr+max) < *(arr + j)) {
				max = j;
			}
		}
		tmp = *(arr + i);
		*(arr + i) = *(arr+max);
		*(arr + max) = tmp;
	}
}

// 제자리 선택 정렬 알고리즘 구현 의사코드 미참조
/*void swapElement_SelectionSort(int* arr, int n) {
	int max, num, tmp;

	for (int i = n; i > 1; i--) {
		max = *arr;
		num = 0;
		for (int j = 0; j < i; j++) {
			if (max < *(arr + j)) {
				max = *(arr + j);
				num = j;
			}
		}
		tmp = *(arr + i - 1);
		*(arr + i - 1) = max;
		*(arr + num) = tmp;
	}
}*/