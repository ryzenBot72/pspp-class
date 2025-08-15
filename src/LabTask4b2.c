/**Write a C program that reads a sequence of integers, from end-user, till the end user presses Ctrl-D (scanf returns -1) and then the program prints the difference of the first and last number (last - first).

The program prints "error" if no numbers are entered.*/
#include <stdio.h>

int main() {
    int first, last, num;
    int count = 0;

    while (scanf("%d", &num) != -1) {
        if (count == 0) {
            first = num;
        }
        last = num;
        count++;
    }

    if (count == 0) {
        printf("error\n");
    } else {
        printf("%d\n", last - first);
    }

    return 0;
}
