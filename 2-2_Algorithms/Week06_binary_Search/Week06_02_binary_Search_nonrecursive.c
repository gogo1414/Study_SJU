#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

/* 이진탐색-비재귀버전
* 문제 2번은 출력의 범위가 다르다 x >= k 즉 key 값보다 같거나 가장 작은 값의 인덱스를 출력하는 문제이다.
* 이 문제는 x <= k와는 다르게 범위 지정을 다르게 해야한다.
* x <= k는 나누기의 경우 홀수의 범위에서 마지막에 (mid)와 같게 지정되기 때문에 상관 없지만 범위가 반대
* 이기 때문에 3개로 나누어서 지정해줘야지 정확한 출력이 된다/
* (범위가 반대로 x >= k 인 경우엔 상관이 없다.)
*/

void inputKey(int*);
int findKey(int*, int);
int size;

int main() {
	int m, *intArray;
	
	scanf("%d %d", &size, &m);
	
	intArray = (int*)malloc(sizeof(int) * size);

	inputKey(intArray);

	printf(" %d", findKey(intArray, m));

	return 0;
}

void inputKey(int* intArray) {
	for (int i = 0; i < size; i++)
		scanf("%d", &intArray[i]);
}

// 8 28 - 92 - 31 - 7 4 14 20 29 44 반례가 나왔는데
// 아래 while문이 끝나는 조건을 기존 mid <= mid1 || mid >= mid2 에서 
// mid1>=mid2로 바꿔서 해결했다.

int findKey(int* intArray, int key) {
	int mid1 = 0, mid2 = size-1;
	int mid = (mid1 + mid2) / 2;
	while(1) {
		if (mid1 >= mid2) {
			if (intArray[mid] >= key)
				return mid;
			else
				return mid+1; // intArray[mid] < key 일 경우 mid+1 값을 반환해야지 정상적으로 작동한다.
		}

		if (intArray[mid] == key) {
			return mid;
		}
		else if (intArray[mid] > key) {
			mid2 = mid-1;
		}
		else {
			mid1 = mid+1;
		}
		mid = (mid1 + mid2) / 2;
	}
}