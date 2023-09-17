#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

int rCnt(char s[], char a, int c);

int main() {
	int len;
	char a, s[100];
	gets(s);
	scanf("%c", &a);
	len = strlen(s);
	printf("%d", rCnt(s+(len-1), a, len));
	return 0;
}

int rCnt(char s[], char a, int c) {
	int x = 0;
	if (c > 0) {
		if (*s == a)
			return rCnt(s - 1, a, --c) + 1;
		else
			return rCnt(s - 1, a, --c) + 0;
	}
	else {
		if (*s == a)
			return 1;
		else
			return 0;
	}
}