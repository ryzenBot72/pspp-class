/**Write a C program that reads a sequence of numbers one after another, until end of input and prints the maximum of those numbers.

All numbers are integers.*/
#include <stdio.h>
int main() {
	int num;
	int max = 0;
	while(scanf("%d", &num) != -1) {
    		if(num > max)
        		max = num;
	}
	printf("%d\n", max);
	return 0;
}
