/**Write a C program which reads an integer n as input from user, and prints the sum of first n terms of this series

sum = 1 + 1/2 + 1/3 + 1/4 + ...*/
#include <stdio.h>
int main(){
	int n;
	double sum = 0;
	int i = 1;
	double t = 0;
	scanf("%d" , &n);
	while(i <= n){
		t = (double) 1/i;
		sum += t;
		i++;
	}
	printf("%.2lf\n" , sum);
	return 0;
}
