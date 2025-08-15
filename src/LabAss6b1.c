/**Write a C program, using functions where the function calculates the factorial of a given integer, and the main() program does I/O and calling of factorial function.*/
#include <stdio.h>
int fact(int n){
	int factorial = 1;
	if(n < 0){
		return 0;
	}
	while(n >= 1){
		factorial *= n;
		n--;
	}
	return factorial;
}
int main(){
	int n;
	int f;
	scanf("%d", &n);
	f = fact(n);
	if(f == 0)
		printf("Invalid Input\n");
	else
		printf("%d\n" , f);
	return 0;
}
