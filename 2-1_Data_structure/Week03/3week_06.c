#include <stdio.h>
#pragma warning(disable:4996)

int rGcd(int a, int b);

int main() {
	int A, B;
	scanf("%d %d", &A, &B);
	rGcd(A, B);
	
	return 0;
}

int rGcd(int a, int b) {
	if (a == 0 || b == 0)
		return a < b ? printf("%d", b) : printf("%d", a);
	return rGcd(b, a % b);
}
