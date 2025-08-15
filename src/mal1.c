/*Write a program that does the following:

    reads an integer number n from end user, then allocates an array of n doubles, then reads n doubles from the end-user, then finds the average of those numbers, and prints it, then frees the allocated memory.*/
#include <stdio.h>
#include <stdlib.h>
int main(){
	int n, i = 0;
	double *p, sum = 0, avg = 0;
	scanf("%d" , &n);
	p = (double *)malloc(sizeof(double) * n);
	while(i < n){
		scanf("%lf" , &p[i]);
		sum += p[i];
		i++;
	}
	avg = sum/n;
	printf("%.2lf\n" , avg);
	return 0;
}
