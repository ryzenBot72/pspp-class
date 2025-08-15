/**Write a C program which

has a function called "max", which takes two ints as arguments, and returns the maximum of the two.

the main() function reads a pairs of numbers, prints the maximum, and continues doing this till the end of input.*/
#include <stdio.h>
int max(int a, int b){
	int m;
	if(a > b)
		m = a;
	else
		m = b;
	return m;
}
int main(){
	int a;
	int b;
	int c = 100;
	int d = 100;
	int e;
	int f;
	int maximum;
	scanf("%d %d %d %d %d %d" , &a , &b , &c , &d , &e, &f);
	maximum = max(a , b);
	printf("%d\n" , maximum);
	if(c != 100 && d != 100){
		maximum = max(c , d);
		printf("%d\n" , maximum);
		maximum = max(e , f);
		printf("%d\n" , maximum);
	}
	return 0;
}
