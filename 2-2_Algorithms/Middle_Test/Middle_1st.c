#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#pragma warning(disable:4996)

/* 제자리 퀵정렬 (중복 가능)
* 이번 문제의 요점은
* 첫째 inPlacePirtition에서 두 개의 pivot을 반환해야 하는 것
* 둘째 두 pivot을 어떻게 지정할 지 생각해야한다.
*/

void inPlaceQuickSort(int*, int, int); // 제자리 퀵정렬 함수이다.
int* inPlacePartition(int*, int, int, int); // 정렬과 함께 두 pivot을 가진 포인터를 반환하는 함수다.
void print_Array(int*, int, int); // 배열을 출력한다.
void swapElement(int*, int, int); // 배열 원소의 위치를 교환한다.

int* Q;

int main() {
	int* intArray, n;

	scanf("%d", &n);
	intArray = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++)
		scanf("%d", &intArray[i]);

	int P = intArray[0];

	inPlaceQuickSort(intArray, 0, n - 1);
	print_Array(intArray, n, P);

	return 0;
}

void print_Array(int* intArray, int n,int P) {
	printf(" %d %d %d", P, Q[0], Q[1]);
	for (int i = 0; i < n; i++) {
		if (intArray[i] < P) printf(" 0");
		else if (intArray[i] == P) printf(" %d", intArray[i]);
		else printf(" 99");
	}
	printf("\n");
}
void swapElement(int* A, int x, int y) {
	int tmp = A[x];
	A[x] = A[y];
	A[y] = tmp;
}
void inPlaceQuickSort(int* L, int l, int r) {
	int* P = NULL;
	int k = l;
	if (l <= r) {
		P = inPlacePartition(L, l, r, k);
		inPlaceQuickSort(L, l, P[0] - 1);
		inPlaceQuickSort(L, P[1] + 1, r);
	}
	Q = P;
	return;
		
}

// 과정을 확인하고자 5 5 3 3 3 1 의 예시를 들었음.
int* inPlacePartition(int* L, int l, int r, int k) {
	int p = L[k], i, j;
	int *P = (int*)malloc(sizeof(int) * 2);



	swapElement(L, k, r);
	i = l;
	j = r - 1;
	// 주석 단 부분은 고민해야할 부분이다.
	// pivot 이상의 값을 모두 오른쪽으로 이동시킨다고 생각한다.
	while (i <= j) {
		while (i <= j && L[i] < p) { // 이하가 아니다. (pivot 이상 값만)
			i = i + 1;
		}
		while (i <= j && L[j] >= p) { // 초과가 아니다. (pivot 미만 값)
			j = j - 1;
		}
		if (i < j)
			swapElement(L, i, j);
	}
	P[0] = i; // 왼쪽 pivot의 위치
	j = r - 1;
	while (i <= j) {
		while (i <= j && L[i] <= p) { // i가 점점 증가해 pivot 초과값에서 멈춘다는 것을 생각한다.
			i = i + 1;
		}
		while (i <= j && L[j] > p) { // 피벗보다 클 경우 (피벗 이하 값이 나와야 함)
			j = j - 1;
		}
		if (i < j)
			swapElement(L, i, j);
	}
	P[1] = i; // 오른쪽 pivot의 위치
	swapElement(L, P[1], r); // P[0] 이 아닌 P[1] 값과 교환이다.
	return P;
}