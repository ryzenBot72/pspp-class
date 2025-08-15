/**Write a program which accepts n as input from user, and then prints the first n numbers of the following series

1 2 4 8 16 32 64 ...

without using multiplication or any library function.  */
#include <stdio.h>
int add(int sum, int a){
	return sum + a;
}
int main(){
	int n;
	int j =0;
	int sum = 0;
	int sum1 = 1;
	int i = 0;
	scanf("%d" , &n);
	while(i < n){
		while(j <= i){
			sum = add(sum , sum1);
			printf("%d " , sum);
			sum1 = sum;
			j++;
		}
		i++;
	}	
	return 0;
}
