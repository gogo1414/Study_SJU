#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

/* 
배열 구현 : 순차힙 
루트에 최대 키 저장 : 최대힙
생성 방식 : 삽입식
연산 효율을 위한 배열 인덱스 0 위치 사용 X
키만 저장
*/


// 전역 배열 H, 힙의 크기로 이용할 n 선언
int H[100], n = 0;


int insertItem(int); // 힙에 키 삽입
int removeMax(); // 힙의 키를 제거
void upHeap(int); // 힙 삽입 시 힙 속성 복구 
void downHeap(int); // 힙 제거 시 힙 속성 복구
void printHeap(); // 힙 키 출력
void swapElements(int, int); // 키 교환


int main() { 
	char N;
	int key;
	
	while (1) {
		scanf("%c", &N);
		if (N == 'i') {
			scanf("%d", &key);
			insertItem(key);
		}
		else if (N == 'd' && n >= 1) {
			printf("%d\n", removeMax());
		}
		else if (N == 'p' && n >= 1) { 
			printHeap(); 
		}
		else if (N == 'q') break;
	}
	return 0;
}

int insertItem(int key) {
	n += 1;
	H[n] = key;
	upHeap(n);
	printf("0\n");
	return;
}

int removeMax() {
	int key = H[1];
	H[1] = H[n];
	n--;
	downHeap(1);
	return key;
}
void upHeap(int index) {
	int parent;
	parent = index / 2;
	if (H[index] <= H[parent] || parent < 1)
		return;
	swapElements(index, parent);
	upHeap(parent);
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

void printHeap() {
	for (int i = 1; i <= n; i++)
		printf(" %d", H[i]);
	printf("\n");
}

void swapElements(int last, int index) {
	int tmp;
	tmp = H[last];
	H[last] = H[index];
	H[index] = tmp;
}