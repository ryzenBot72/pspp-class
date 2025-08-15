/**Write a C program that reads integers one after another, until the number -1 is entered, and prints their sum of numbers including last -1.*/
#include <stdio.h>
int main() {
	int n;
	int sum = 0;
	scanf("%d" , &n);
	while(n != -1){
		sum += n;
		scanf("%d" , &n);
	}
	sum--;
	printf("%d", sum);
	return 0;
}
