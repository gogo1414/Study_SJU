#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

struct student {
    char name[7];
    int korea, english, math;
    double avg;
};

int main() {
    int N, i, j;
    struct student* stu;

    scanf("%d", &N);

    stu = (struct student*)malloc(sizeof(struct student) * N);

    for (i = 0; i < N; i++) {
        scanf("%s %d %d %d", stu[i].name, &stu[i].korea, &stu[i].english, &stu[i].math);
        stu[i].avg = (double)(stu[i].english + stu[i].korea + stu[i].math) / 3;
    }
    for (i = 0; i < N; i++) {
        if (stu[i].korea >= 90 || stu[i].math >= 90 || stu[i].english >= 90)
            if (stu[i].korea < 70 || stu[i].math < 70 || stu[i].english < 70)
                printf("%s %.1lf GREAT BAD\n", stu[i].name, stu[i].avg);
            else
                printf("%s %.1lf GREAT\n", stu[i].name, stu[i].avg);
        else
            if (stu[i].korea < 70 || stu[i].math < 70 || stu[i].english < 70)
                printf("%s %.1lf BAD\n", stu[i].name, stu[i].avg);
            else
                printf("%s %.1lf\n", stu[i].name, stu[i].avg);
    }

    return 0;
}