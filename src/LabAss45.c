/**Write a C program that reads a sequence of numbers and finds the third maximum among those numbers. If the sequence has less than 3 numbers, then the program prints "not found".

The sequence of numbers input is terminated by the end-user with Ctrl-D.*/
#include <stdio.h>
int main(){
	int n;
	int fmax = -2;
	int smax = -2;
	int tmax = -2;
	int c= 0;
	
	while(scanf("%d" , &n)!= -1){
		if(n > fmax){
			tmax = smax;
			smax = fmax;
			fmax = n;
		}
		else if(n > smax){
			tmax = smax;
			smax = n;
		}
		else if(n > tmax)
			tmax = n;
		else
			continue;
		c++;
	}	
	if(c < 3)
		printf("not found\n");
	else
		printf("%d\n", tmax);
	return 0;
}

