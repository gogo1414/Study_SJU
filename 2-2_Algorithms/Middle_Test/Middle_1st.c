#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#pragma warning(disable:4996)

/* ���ڸ� ������ (�ߺ� ����)
* �̹� ������ ������
* ù° inPlacePirtition���� �� ���� pivot�� ��ȯ�ؾ� �ϴ� ��
* ��° �� pivot�� ��� ������ �� �����ؾ��Ѵ�.
*/

void inPlaceQuickSort(int*, int, int); // ���ڸ� ������ �Լ��̴�.
int* inPlacePartition(int*, int, int, int); // ���İ� �Բ� �� pivot�� ���� �����͸� ��ȯ�ϴ� �Լ���.
void print_Array(int*, int, int); // �迭�� ����Ѵ�.
void swapElement(int*, int, int); // �迭 ������ ��ġ�� ��ȯ�Ѵ�.

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

// ������ Ȯ���ϰ��� 5 5 3 3 3 1 �� ���ø� �����.
int* inPlacePartition(int* L, int l, int r, int k) {
	int p = L[k], i, j;
	int *P = (int*)malloc(sizeof(int) * 2);



	swapElement(L, k, r);
	i = l;
	j = r - 1;
	// �ּ� �� �κ��� ����ؾ��� �κ��̴�.
	// pivot �̻��� ���� ��� ���������� �̵���Ų�ٰ� �����Ѵ�.
	while (i <= j) {
		while (i <= j && L[i] < p) { // ���ϰ� �ƴϴ�. (pivot �̻� ����)
			i = i + 1;
		}
		while (i <= j && L[j] >= p) { // �ʰ��� �ƴϴ�. (pivot �̸� ��)
			j = j - 1;
		}
		if (i < j)
			swapElement(L, i, j);
	}
	P[0] = i; // ���� pivot�� ��ġ
	j = r - 1;
	while (i <= j) {
		while (i <= j && L[i] <= p) { // i�� ���� ������ pivot �ʰ������� ����ٴ� ���� �����Ѵ�.
			i = i + 1;
		}
		while (i <= j && L[j] > p) { // �ǹ����� Ŭ ��� (�ǹ� ���� ���� ���;� ��)
			j = j - 1;
		}
		if (i < j)
			swapElement(L, i, j);
	}
	P[1] = i; // ������ pivot�� ��ġ
	swapElement(L, P[1], r); // P[0] �� �ƴ� P[1] ���� ��ȯ�̴�.
	return P;
}