#include <stdio.h>
#pragma warning(disable:4996)

int mostOnes(int A[100][100], int n);

int main() {
	int n, A[100][100] = { 0, };
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			scanf("%d", &A[i][j]);
	}

	printf("%d\n", mostOnes(A, n));


	return 0;
}

int mostOnes(int A[100][100], int n) {
	int s = 0, res = 0;
	for (int i = 0; i < n; i++) {
		if (A[s][i] == 0) {
			if (++s == n)
				break;
			if (A[s][i] == 1) {
				res = s;
			}
			else {
				s++, i--;
				if (s == n)
					break;
			}
		}

		else if (A[s][i] == 1) {
			res = s;
		}
		//		printf("%d\n", res);
	}
	return res;
}