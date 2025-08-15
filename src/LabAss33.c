/*Write a C program that reads 4 integers and then prints the 2 numbers, which will be in the middle if the four numbers were sorted in ascending order, without changing the order of appearance of those two numbers in input.

For example, if the input was: 7 3 10 4, then (since the sorted order is 3 4 7 10) the program prints 7 4  (in that order)*/
#include <stdio.h>
int main() {
	int a, b, c, d;
	
	scanf(" %d %d %d %d" , &a , &b , &c , &d);
	
	//finding max
	int max = a;
	if(max < b)
		max = b;
	if(max <c)
		max = c;
	if(max < d)
		max = d;
		
	//finding min
	int min = a;
	if(min > b)
		min = b;
	if(min > c)
		min = c;
	if(min > d)
		min = d;
		
	/*finding the two numbers*/
	//checking a
	if(a != max && a != min)
		printf("%d ", a);
	if(b != max && b != min)
		printf("%d ", b);
	if(c != max && c != min)
		printf("%d ", c);
	if(d != max && d != min)
		printf("%d ", d);
		
	return 0;
}
