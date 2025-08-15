/**Write a function which takes three integers as arguments, and returns the maximum of the three. The main() function then tests this function appropriately.*/
#include <stdio.h>
int max(int a, int b, int c){
	if(a > b){
		if(a > c)
			return a;
		else
			return c;
	}
	else{
		if(b > c)
			return b;
		else
			return c;
	}
}
int main(){
	int a, b , c;
	scanf("%d %d %d" , &a , &b , &c);
	int maximum = max(a,b,c);
	printf("%d\n" , maximum);
	return 0;
}
