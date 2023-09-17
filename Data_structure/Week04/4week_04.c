#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)


int main() {
	int N1, N2, n1, n2, cnt = 1, row = 0, col = -1, step = 1, ** arr;
	scanf("%d %d", &N1, &N2);
	n1 = N1, n2 = N2; // 나중에 출력 값을 위해 미리 저장

	arr = (int**)malloc(sizeof(int*) * N1); // arr배열에 N1크기의 행 할당

	for (int i = 0; i < N1; i++)
		arr[i] = (int*)malloc(sizeof(int) * N2); // arr배열에 N2 크기의 열 할당
	
	while (cnt <= n1*n2) { // cnt가 N1*N2(=n1*n2)의 크기까지 반복
		for (int i = 0; i < N2; i++) { // 행은 고정 열만 1씩증가
			col += step; // 열의 크기 1증가
			arr[row][col] = cnt++;
		}
		N2--; // 반복 조건의 수를 줄여 다음 반복을 미리 생각함.
		for (int j = 0; j < N1-1; j++) { // 행의 크기 증가 열은 고정
			row += step; // 행의 크기 1씩 증가
			arr[row][col] = cnt++;
		}
		N1--; // 반복 조건의 수를 줄여 다음 반복 미리 생각.
		step *= -1; // 되돌아가야하기 때문에 음수로 바꿔줌 
	}
	for (int i = 0; i < n1; i++) { // 출력
		for (int j = 0; j < n2; j++)
			printf(" %d", arr[i][j]);
		printf("\n");
	}

	for (int i = 0; i < N1; i++)
		free(arr[i]);
	free(arr);

	return 0;
}