#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

struct time {
    int hour, minute, second;
};

int main() {
    struct time first_time;
    struct time second_time;

    scanf("%d %d %d", &first_time.hour, &first_time.minute, &first_time.second);
    scanf("%d %d %d", &second_time.hour, &second_time.minute, &second_time.second);

    if (first_time.second > second_time.second) {
        if (first_time.minute > second_time.minute) {
            printf("%d %d %d", second_time.hour - first_time.hour - 1, 60 - (first_time.minute - second_time.minute + 1), 60 - (first_time.second - second_time.second));
        }
        else
            printf("%d %d %d", second_time.hour - first_time.hour, second_time.minute - first_time.minute - 1, 60 - (first_time.second - second_time.second));
    }
    else if (first_time.minute > second_time.minute) {
        printf("%d %d %d", second_time.hour - first_time.hour - 1, 60 - (first_time.minute - second_time.minute), second_time.second - first_time.second);
    }
    else
        printf("%d %d %d", second_time.hour - first_time.hour, second_time.minute - first_time.minute, second_time.second - first_time.second);
    return 0;
}
