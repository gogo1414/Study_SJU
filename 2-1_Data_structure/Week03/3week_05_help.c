#include <stdio.h>
#pragma warning (disable:4996)

int rHanoi(int N, char from, char aux, char to);

int main() {
	int N;
	scanf("%d", &N);
	rHanoi(N,'A','B','C');

	return 0;
}

int rHanoi(int n,char from, char aux, char to) {
	if (n == 1) {
		printf("%c %c\n", from, to);
		return 0;
	}
	rHanoi(n - 1, from, to, aux);
	printf("%c %c\n", from, to);
	rHanoi(n - 1, aux, from, to);
	return 0;
}