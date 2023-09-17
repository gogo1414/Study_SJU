#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)


int main() {
    char str1[100], tmp, tmp1;
    int i, j;
    scanf("%s", &str1);
    printf("%s\n", str1);
    for (i = 0; i < strlen(str1) - 1; i++) {
        tmp = str1[0];
        for (j = 0; j < strlen(str1) - 1; j++) {
            str1[j] = str1[j + 1];
        }
        str1[strlen(str1) - 1] = tmp;
        printf("%s\n", str1);
    }

    return 0;
}
