/*Write a program that does the following:
    reads an integer number n from end user, then allocates an array of n doubles, then reads n doubles from the end-user, then finds the average of those numbers, and prints it, then frees the allocated memory.*/
#include <stdio.h>
#include <stdlib.h>
int main(){
	int n;
	double *p, sum, avg;
	scanf("%d" , &n);
	p = (double *)malloc(sizeof(double) * n);
	for(int i =0;i < n;i++){
		scanf("%lf" , &p[i]);
		sum += p[i];
	}
	avg = sum/n;
	printf("Average : %.2lf\n" , avg);
	free(p);
	return 0;
}
