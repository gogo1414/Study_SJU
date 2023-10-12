#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

/* 이진탐색-재귀버전 (의사코드 미참조)
* 의사코드를 보지 않고 재귀로 이진탐색을 구현한 버전이다.
*/

void inputKey(int*, int); // 배열 입력 함수
int findKey(int*, int, int); // 이진탐색 함수
int key; // 전역변수로 찾을 key 선언

int main() {
	int *intArray, a = 0, size;

	scanf("%d %d", &size, &key); // size와 key 값 입력
	
	intArray = (int*)malloc(sizeof(int) * size); // 배열 size 동적할당
	inputKey(intArray, size); // 배열 입력

	printf(" %d\n",findKey(intArray, a, size-1)); // 배열의 크기를 인자로 줄때 size-1 로 줘야한다.
	return 0;
}

void inputKey(int* intArray, int n) {
	for (int i = 0; i < n; i++)
		scanf("%d", &intArray[i]);
}

// 2번을 해결한 방안을 토대로 작성하여 틀린 점이 동일하다.

int findKey(int* intArray, int a, int b) {
	int x, mid = (a + b) / 2; 
	if (a >= b) { // mid가 전 mid와 같아질 때 재귀를 멈추고 판단한다.
		if (intArray[mid] <= key)
			return mid;
		else return mid-1; // 부호가 반대로 작용하기 때문에 m-1 값을 반환한다.
	}
	if (intArray[mid] <= key) {
		x = findKey(intArray, mid+1, b);
	}
	else {
		x = findKey(intArray, a, mid-1);
	}
}