#include <stdio.h>
#pragma warning(disable:4996)

int modulo(int a, int b);

int main() {
	int n1, n2, res = 0;

	scanf("%d %d", &n1, &n2);
	res = modulo(n1, n2);
	printf("%d\n", res);

	return 0;
}

int modulo(int a, int b) {
	int  cnt = 0;
	while (a >= b) {
		a = a - b;
	}
	return a;
}