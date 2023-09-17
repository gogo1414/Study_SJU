#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

/* ���ڸ� ���� ���� (�ǻ��ڵ� ������ ����) 
   �ش� ������ �ڵ�� �ּ�ó��             */

/* ���ڸ� ���� ���� (�ǻ��ڵ� ���� ����) */

void swapElement_InsertSort(int*, int);

int main() {
	int n, *arr;

	// �迭 ũ�� �Է�
	scanf("%d", &n);

	// �迭 ũ�� n �Ҵ�
	arr = (int*)malloc(sizeof(int) * n);

	if (arr == NULL) {
		printf("�޸� ����");
		return 0;
	}

	for (int i = 0; i < n; i++)
		scanf("%d", arr + i);

	swapElement_InsertSort(arr, n);

	for (int i = 0; i < n; i++)
		printf(" %d", *(arr + i));
	
	// �޸� �Ҵ� ����
	free(arr);

	return 0;
}

// ���ڸ� �������� (�ǻ��ڵ� ����)
void swapElement_InsertSort(int* arr, int n) {
	int min, j;

	for (int i = 1; i < n; i++) {
		min = *(arr+i);
		j = i - 1;           
		while ((j >= 0) && (*(arr + j) > min)) {
			*(arr + j + 1) = *(arr + j);
			j = j - 1;
		}
		*(arr + j + 1) = min;
	}

	return;
}

/* ���ڸ� ��������(�ǻ��ڵ� ������)
void swapElement_InsertSort(int* arr, int n) {
	int tmp, num, min;

	for (int i = 0; i < n - 1; i++) {
		min = *(arr + n - 1);
		num = n-1;
		for (int j = n-1; j >= i; j--) {
			if (min > *(arr + j)) {
				min = *(arr + j);
				num = j;
			}
		}
		tmp = *(arr + i);
		*(arr + i) = min;
		*(arr + num) = tmp;
	}

	return;
}*/