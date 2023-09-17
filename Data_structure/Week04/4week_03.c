#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)


int main() {
	int N, cnt = 0, row = 0, col = 0,  ** arr;
	scanf("%d", &N);

	arr = (int**)malloc(sizeof(int*) * N); // ũ�Ⱑ N�� �� �Ҵ�

	for (int i = 0; i < N; i++)
		arr[i] = (int*)malloc(sizeof(int) * N); //�� �࿡ ũ�Ⱑ N�� �� �Ҵ�

	while (cnt < (N * N)) {
		if (row % 2 == 0) { // ���� 0�� ������ ¦���� ��
			arr[row][col++] = cnt + 1; // col�� 1�� ���Ѵ�.
		}
		else { // ���� Ȧ���� ��
			arr[row][--col] = cnt + 1; // ���� col�� 1�� ���� �� ���� ���.
		}
		cnt += 1; // n*n ���� ī��Ʈ���ְ� ����� ������ å������ �༮
		if (cnt % N == 0)
			row++; // �� ���� ������ ���� �ٲ��ش�.
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			printf(" %d", arr[i][j]);
		printf("\n");
	}

	for (int i = 0; i < N; i++)
		free(arr[i]);
	free(arr);

	return 0;
}