#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)


int main() {
	int N1, N2, n1, n2, cnt = 1, row = 0, col = -1, step = 1, ** arr;
	scanf("%d %d", &N1, &N2);
	n1 = N1, n2 = N2; // ���߿� ��� ���� ���� �̸� ����

	arr = (int**)malloc(sizeof(int*) * N1); // arr�迭�� N1ũ���� �� �Ҵ�

	for (int i = 0; i < N1; i++)
		arr[i] = (int*)malloc(sizeof(int) * N2); // arr�迭�� N2 ũ���� �� �Ҵ�
	
	while (cnt <= n1*n2) { // cnt�� N1*N2(=n1*n2)�� ũ����� �ݺ�
		for (int i = 0; i < N2; i++) { // ���� ���� ���� 1������
			col += step; // ���� ũ�� 1����
			arr[row][col] = cnt++;
		}
		N2--; // �ݺ� ������ ���� �ٿ� ���� �ݺ��� �̸� ������.
		for (int j = 0; j < N1-1; j++) { // ���� ũ�� ���� ���� ����
			row += step; // ���� ũ�� 1�� ����
			arr[row][col] = cnt++;
		}
		N1--; // �ݺ� ������ ���� �ٿ� ���� �ݺ� �̸� ����.
		step *= -1; // �ǵ��ư����ϱ� ������ ������ �ٲ��� 
	}
	for (int i = 0; i < n1; i++) { // ���
		for (int j = 0; j < n2; j++)
			printf(" %d", arr[i][j]);
		printf("\n");
	}

	for (int i = 0; i < N1; i++)
		free(arr[i]);
	free(arr);

	return 0;
}