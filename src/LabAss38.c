/*Write a program that reads an amount as input. Assume that amount is always more than 0 (no need to check errors).

Assuming that the denominations of the following notes are available 100, 50, 20, 5, 1

the program prints the count of notes of each denomination required, in descending order of denominations, such that the minimum number of notes is required. the program also prints the Total number of notes.*/
#include <stdio.h>
int main() {
	int total , rem, sum;
	int n100, n50, n20, n5, n1;
	scanf(" %d", &total);
	n100 = total / 100;
	rem = total % 100;
	n50 = rem / 50;
	rem = rem % 50;
	n20 = rem / 20;
	rem = rem % 20;
	n5 = rem / 5;
	rem = rem % 5;
	n1 = rem / 1;
	if(n100 !=0)
		printf("100 %d " , n100);
	if(n50 != 0)
		printf("50 %d ", n50);
	if(n20 != 0)
		printf("20 %d ", n20);
	if(n5 != 0)
		printf("5 %d ", n5);
	if(n1 != 0)
		printf("1 %d ", n1);
	sum = n100 + n50 + n20 + n5 + n1;
	printf("%d" , sum);
	return 0;
}
