#include <stdio.h>
#pragma warning(disable:4996)

/*
 삽입식, 상향식 두 종류 모두 구현
 기존 downHeap과 거의 비슷하지만 last 라는 새로운 인자를 추가하여 제자리 정렬에 용이하게 만듦
 중복 키를 입력했을 때 정상적으로 나오는 것으로 보아 수정이 필요해보이진 않는다.
*/

int H[100], n = 0;

void inPlaceHeapSort(); // 제자리 힙 정렬
void printArray();
void downHeap(int, int);
void insertItem(int);
void upHeap(int);
void rBuildHeap(int);
void BuildHeap();
void swapElements(int, int);

int main() {
	int N, key;

	scanf("%d", &N);

	//삽입식
	for (int i = 0; i < N; i++) {
		scanf("%d", &key);
		insertItem(key);
	}

	//상향식
	/*for (int i = 1; i <= N; i++) {
		n++;
		scanf("%d", &H[i]);
	}*/
	//rBuildHeap(1);
	//BuildHeap();
	
	inPlaceHeapSort();
	printArray();

	return 0;
}

void inPlaceHeapSort() {
	for (int i = n; i >= 2; i--) {
		swapElements(1, i);
		downHeap(1,i-1);
	}
	return;
}

void insertItem(int key) {
	n += 1;
	H[n] = key;
	upHeap(n);
}

void downHeap(int index, int last) {
	int left = index * 2, right = index*2+1;
	if (left > last && right > last)
		return;
	int greater = left;
	if (right <= last)
		if (H[greater] < H[right])
			greater = right;
	if (H[index] >= H[greater])
		return;
	swapElements(index, greater);
	downHeap(greater, last);
}

void upHeap(int index) {
	int parent = index / 2;
	if (H[index] <= H[parent] || parent < 1)
		return;
	swapElements(index, parent);
	upHeap(parent);
}

void rBuildHeap(int index) {
	if (index > n) return;
	rBuildHeap(index * 2); // left
	rBuildHeap(index * 2 + 1); // right;
	downHeap(index, n);
	return;
}

void BuildHeap() {
	for(int i = n / 2; i > 0; i--)
		downHeap(i, n);
	return;
}

void printArray() {
	for (int i = 1; i <= n; i++)
		printf(" %d", H[i]);
}

void swapElements(int a, int b) {
	int tmp = H[a];
	H[a] = H[b];
	H[b] = tmp;
}