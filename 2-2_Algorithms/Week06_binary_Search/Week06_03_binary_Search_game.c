#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int main() {
	int a, b, k, m, c;
	scanf("%d %d %d", &a, &b, &k); // a <= k <= b
	getchar();

	while ((c = getchar()) != EOF && c != '\n') {
		m = (a + b) / 2;
		if (c == 'Y') { // m < k && k <= b
			a = m + 1;
		}
		else if (c == 'N') { // a <= k && k <= m
			b = m;
		}
		else {
			return m;
		}
		if (a == b)
			printf(" %d\n", a);
	}

	return 0;
}