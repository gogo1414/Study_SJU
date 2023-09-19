#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

/*
배열 구현 : 순차힙
루트에 최대 키 저장 : 최대힙
생성 방식 : 상향식
연산 효율을 위한 배열 인덱스 0 위치 사용 X
키만 저장
*/


// 전역 배열 H, 힙의 크기로 이용할 n 선언
int H[100], n = 0;

void rBuildHeap(int); // 재귀
void buildHeap(); // 비재귀
void downHeap(int);
void printHeap();
void swapElements(int, int);

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &H[i]);
	}
	//rBuildHeap(1);
	buildHeap();
	printHeap();
	return 0;
}

void rBuildHeap(int index) {
	if (index > n) return;
	rBuildHeap(2 * index);
	rBuildHeap(2 * index + 1);
	downHeap(index);
	return;
}

void buildHeap() {
	for (int i = n / 2; i >= 1; i--)
		downHeap(i);
	return;
}

void downHeap(int index) {
	int left, right, greater;
	left = index * 2;
	right = index * 2 + 1;
	if (left > n && right > n)
		return;
	greater = left;
	if (right <= n)
		if (H[right] > H[greater])
			greater = right;
	if (H[index] >= H[greater])
		return;
	swapElements(index, greater);
	downHeap(greater);
}

void swapElements(int a, int b) {
	int tmp;
	tmp = H[a];
	H[a] = H[b];
	H[b] = tmp;
}

void printHeap() {
	for (int i = 1; i <= n; i++)
		printf(" %d", H[i]);
}