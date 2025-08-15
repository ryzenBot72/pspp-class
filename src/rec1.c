/*Write recursive functions for the following:

* add two numbers*/
#include <stdio.h>
int add(int a, int b){
	if(b == 0)
		return a;
	return 1 + add(a, b-1);
}
int main(){
	int a, b;
	scanf("%d %d" , &a, &b);
	int sum = add(a, b);
	printf("%d\n" , sum);
	return 0;
}
