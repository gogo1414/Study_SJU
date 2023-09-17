#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)


int main() {
	int i, j = 0, N1, N2, res = 0, cnt = 1, ** arr;
	scanf("%d %d", &N1, &N2);

	arr = (int**)malloc(sizeof(int*) * N1); // arr배열에 N1크기의 행 할당

	for ( i = 0; i < N1; i++)
		arr[i] = (int*)malloc(sizeof(int) * N2); // arr배열에 N2 크기의 열 할당
	
	while (cnt <= N1 * N2) { // cnt가 N1*N2(=n1*n2)의 크기까지 반복
		for (i = 0; i < N1; i++) {
			for (j = 0; j < N2; j++) {
				if (i + j == res) {
					arr[i][j] = cnt++;
				}
			}
		}
		res++;
	}
	for ( i = 0; i < N1; i++) {
		for (j = 0; j < N2; j++)
			printf(" %d", arr[i][j]);
		printf("\n");
	}

	for (int i = 0; i < N1; i++)
		free(arr[i]);
	free(arr);

	return 0;
}