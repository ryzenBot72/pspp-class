/*Write a program that reads data in an array of following structs, and then finds the struct with the smallest name in dictionary order (use strcmp() library function for this) and prints that struct. Use some proper #define to define account types, or you can use an enum for the same.

struct  account { int acctid; char name[32]; double amount; int type; }*/
#include <stdio.h>
#include <string.h>
#define SAVINGS 1
#define DEPOSIT 2
typedef struct account{
	int acctid;
	char name[32];
	double amount;
	int type;
}account;
int main(){
	account a[32];
	int i = 0 , k, min;
	while(scanf("%d %s %lf %d" , &a[i].acctid, &a[i].name, &a[i].amount, &a[i].type) == 4)
		i++;
	for(int j = 0; j < i; j++){
		k = strcmp(&a[j].name, a[j+1].name);
		if(k < 0)
			min = j;
	}
	printf("Account Number : %d\n" , a[min].acctid);
	printf("Name : %s\n" , a[min].name);
	printf("Amount : %lf\n" , a[min].amount);
	printf("Type : %d\n" , a[min].type);
	return 0;
}
