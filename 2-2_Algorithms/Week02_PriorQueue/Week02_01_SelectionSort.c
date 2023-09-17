#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

/* ���ڸ� �������� (�ǻ��ڵ� ������ ����) 
   �ش� ������ �ڵ�� �ּ�ó��             */

/* ���ڸ� �������� (�ǻ��ڵ� ���� ����)  */
void swapElement_SelectionSort(int*, int);

int main() {
	int n, *arr;
	
	// �迭�� ũ�� �Է�
	scanf("%d", &n);
	
	// �迭�� ũ�� n �����Ҵ�
	arr = (int*)malloc(n*sizeof(int));
	if (arr == NULL) {
		printf("�޸𸮰� ������� �ʽ��ϴ�!");
		return 0;
	}
	// �ʱ� ���� �Է�
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i);

	swapElement_SelectionSort(arr, n);

	for (int i = 0; i < n; i++)
		printf(" %d", *(arr + i));

	free(arr);

	return 0;
}

// ���ڸ� ���� ���� �˰��� �ǻ��ڵ� ����
void swapElement_SelectionSort(int* arr, int n) {
	int max, tmp;

	for (int i = n-1; i >= 1; i--) {
		max = i;
		for (int j = i-1; j >= 0; j--) {
			if (*(arr+max) < *(arr + j)) {
				max = j;
			}
		}
		tmp = *(arr + i);
		*(arr + i) = *(arr+max);
		*(arr + max) = tmp;
	}
}

// ���ڸ� ���� ���� �˰��� ���� �ǻ��ڵ� ������
/*void swapElement_SelectionSort(int* arr, int n) {
	int max, num, tmp;

	for (int i = n; i > 1; i--) {
		max = *arr;
		num = 0;
		for (int j = 0; j < i; j++) {
			if (max < *(arr + j)) {
				max = *(arr + j);
				num = j;
			}
		}
		tmp = *(arr + i - 1);
		*(arr + i - 1) = max;
		*(arr + num) = tmp;
	}
}*/