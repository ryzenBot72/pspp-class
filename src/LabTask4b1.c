/**Write a C program that reads a number (say n), and then reads 'n' number of integers and prints the average of those 'n' integers, as a real number, upto decimal points.

Program prints 0.0000 if n<=0*/
#include <stdio.h>
int main() {
	int n;
	double sum = 0;
	double avg = 0;
	scanf("%d ", &n);
	if(n > 0){
	int t = n;
		while(n > 0){
			int num;
			scanf("%d ", &num);
			sum = sum + num;
			n--;
		}
	avg = sum / t;
	printf("%.4lf" , avg);
	}else{
		printf("%.4lf" , avg);
	}
	return 0;
}
