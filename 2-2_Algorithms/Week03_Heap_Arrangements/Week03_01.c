#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

/* 
�迭 ���� : ������ 
��Ʈ�� �ִ� Ű ���� : �ִ���
���� ��� : ���Խ�
���� ȿ���� ���� �迭 �ε��� 0 ��ġ ��� X
Ű�� ����
*/


// ���� �迭 H, ���� ũ��� �̿��� n ����
int H[100], n = 0;


int insertItem(int); // ���� Ű ����
int removeMax(); // ���� Ű�� ����
void upHeap(int); // �� ���� �� �� �Ӽ� ���� 
void downHeap(int); // �� ���� �� �� �Ӽ� ����
void printHeap(); // �� Ű ���
void swapElements(int, int); // Ű ��ȯ


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