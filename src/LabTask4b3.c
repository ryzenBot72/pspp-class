/**Write a C program that reads a sequence of integers, until the end-user pressed Ctrl-D (scanf returns -1) and then prints the minimum of all those numbers.

Program prints "error" if no input is specified.*/
#include <stdio.h>

int main() {
    int num, min = 1000;
    int count = 0;

    while (scanf("%d", &num) != -1) {
        if (num < min) {
            min = num;
        }
        count++;
    }

    if (count == 0) {
        printf("error\n");
    } else {
        printf("%d\n", min);
    }

    return 0;
}
