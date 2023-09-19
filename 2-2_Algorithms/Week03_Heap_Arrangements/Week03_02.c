#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

/*
�迭 ���� : ������
��Ʈ�� �ִ� Ű ���� : �ִ���
���� ��� : �����
���� ȿ���� ���� �迭 �ε��� 0 ��ġ ��� X
Ű�� ����
*/


// ���� �迭 H, ���� ũ��� �̿��� n ����
int H[100], n = 0;

void rBuildHeap(int); // ���
void buildHeap(); // �����
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