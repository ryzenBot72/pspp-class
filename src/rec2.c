/*Write recursive functions for the following:

* subtract two numbers*/
#include <stdio.h>
int sub(int a, int b){
	if(a == b)
		return 1;
	return a - sub(a, b+1);
}

int main(){
	int a, b;
	scanf("%d %d" , &a, &b);
	int r = sub(a, b);
	printf("%d\n" , r);
	return 0;
}
