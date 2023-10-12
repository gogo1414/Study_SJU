#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

/* ����Ž��-��͹��� (�ǻ��ڵ� ������)
* �ǻ��ڵ带 ���� �ʰ� ��ͷ� ����Ž���� ������ �����̴�.
*/

void inputKey(int*, int); // �迭 �Է� �Լ�
int findKey(int*, int, int); // ����Ž�� �Լ�
int key; // ���������� ã�� key ����

int main() {
	int *intArray, a = 0, size;

	scanf("%d %d", &size, &key); // size�� key �� �Է�
	
	intArray = (int*)malloc(sizeof(int) * size); // �迭 size �����Ҵ�
	inputKey(intArray, size); // �迭 �Է�

	printf(" %d\n",findKey(intArray, a, size-1)); // �迭�� ũ�⸦ ���ڷ� �ٶ� size-1 �� ����Ѵ�.
	return 0;
}

void inputKey(int* intArray, int n) {
	for (int i = 0; i < n; i++)
		scanf("%d", &intArray[i]);
}

// 2���� �ذ��� ����� ���� �ۼ��Ͽ� Ʋ�� ���� �����ϴ�.

int findKey(int* intArray, int a, int b) {
	int x, mid = (a + b) / 2; 
	if (a >= b) { // mid�� �� mid�� ������ �� ��͸� ���߰� �Ǵ��Ѵ�.
		if (intArray[mid] <= key)
			return mid;
		else return mid-1; // ��ȣ�� �ݴ�� �ۿ��ϱ� ������ m-1 ���� ��ȯ�Ѵ�.
	}
	if (intArray[mid] <= key) {
		x = findKey(intArray, mid+1, b);
	}
	else {
		x = findKey(intArray, a, mid-1);
	}
}