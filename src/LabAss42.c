/**The binomial theorem tells us that the coefficient nCr of the r'th power of x in the expansion of (x+1)n

is given by

nCr = n!  / ((r!)(n-r!))

For example

(x+1)3=  x3 + 3x2 + 3x + 1  , and 1 3 3 1 are the coefficients, for n = 3 and r = 3, 2,1, 0 respectively.

Write a C program, which given n, prints all the coefficients of xr in the expansion of (x+1)n*/
#include <stdio.h>
int fact(int a){
	int f = 1;
	while(a >= 1){
		f *= a;
		a--;
	}
	return f;
}
int main(){
	int n;
	int r;
	int t;
	scanf("%d" , &n);
	r = n;
	while(r >= 0){
		t = fact(n) / (fact(r) * fact (n - r));
		printf("%d ", t);
		r--;
	}
	return 0;
}
