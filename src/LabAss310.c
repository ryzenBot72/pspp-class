/*Write a program to check if a non-negative whole number entered by the user is a multiple of 9 or not.*/
#include <stdio.h>
int main() {
	int n;
	scanf(" %d" , &n);
	if(n >= 0){
		if(n % 9 == 0)
			printf("multiple");
		else
			printf("not-multiple");
	}else
		printf("invalid");
	return 0;
}
