#include <stdio.h>
#pragma warning(disable:4996)

struct test {
    char name[9];
    int grade;
};

int main() {
    struct test stu[5];
    int avg = 0;
    for (int i = 0; i < 5; i++) {
        scanf("%s %d", stu[i].name, &stu[i].grade);
        avg += stu[i].grade;
    }

    avg = (int)avg / 5;

    for (int i = 0; i < 5; i++) {
        if (avg >= stu[i].grade)
            printf("%s", stu[i].name);
    }

    return 0;
}