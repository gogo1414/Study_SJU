#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)


int main() {
	int N, cnt = 0, row = 0, col = 0,  ** arr;
	scanf("%d", &N);

	arr = (int**)malloc(sizeof(int*) * N); // 크기가 N인 행 할당

	for (int i = 0; i < N; i++)
		arr[i] = (int*)malloc(sizeof(int) * N); //각 행에 크기가 N인 열 할당

	while (cnt < (N * N)) {
		if (row % 2 == 0) { // 행이 0을 포함한 짝수일 때
			arr[row][col++] = cnt + 1; // col을 1씩 더한다.
		}
		else { // 행이 홀수일 때
			arr[row][--col] = cnt + 1; // 기존 col에 1을 먼저 뺀 다음 계산.
		}
		cnt += 1; // n*n 까지 카운트해주고 행렬의 값까지 책임지는 녀석
		if (cnt % N == 0)
			row++; // 한 열을 지나면 행을 바꿔준다.
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