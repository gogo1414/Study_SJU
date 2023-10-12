#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

/* ����Ž��-����͹���
* ���� 2���� ����� ������ �ٸ��� x >= k �� key ������ ���ų� ���� ���� ���� �ε����� ����ϴ� �����̴�.
* �� ������ x <= k�ʹ� �ٸ��� ���� ������ �ٸ��� �ؾ��Ѵ�.
* x <= k�� �������� ��� Ȧ���� �������� �������� (mid)�� ���� �����Ǳ� ������ ��� ������ ������ �ݴ�
* �̱� ������ 3���� ����� ����������� ��Ȯ�� ����� �ȴ�/
* (������ �ݴ�� x >= k �� ��쿣 ����� ����.)
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

// 8 28 - 92 - 31 - 7 4 14 20 29 44 �ݷʰ� ���Դµ�
// �Ʒ� while���� ������ ������ ���� mid <= mid1 || mid >= mid2 ���� 
// mid1>=mid2�� �ٲ㼭 �ذ��ߴ�.

int findKey(int* intArray, int key) {
	int mid1 = 0, mid2 = size-1;
	int mid = (mid1 + mid2) / 2;
	while(1) {
		if (mid1 >= mid2) {
			if (intArray[mid] >= key)
				return mid;
			else
				return mid+1; // intArray[mid] < key �� ��� mid+1 ���� ��ȯ�ؾ��� ���������� �۵��Ѵ�.
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