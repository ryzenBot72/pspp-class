/**Write a program to compute Cosine(x), given x.

Use the Series

cos(x) = 1 - x2/2! + x4/4! - x6/6! + ...

Stop when 6 decimal point precision is achieved (1e-6)

Write the answer upto 4 decimal points. */
#include <stdio.h>
double power(double x, double i){
	double pr = 1;
	if(i < 0){
		i = 0 - i;
		while(i > 0){
			pr *= x;
			i--;
		}
		return (1/pr);
	}
	else{
		while(i > 0){
			pr *= x;
			i--;
		}
	}
	return pr;
}
double fact(double i){
	double f = 1;
	while(i > 0){
		f *= i;
		i--;
	}
	return f;
}
int main(){
	double i = 2;
	int c = 1;
	double x;
	double cosx = 1;
	scanf("%lf" , &x);
	double t = 1;
	if(x > 6.283184){
		while(x > 6.283184){
			x -= 6.283184;
		}
	}
	while(t > 0.000001){
		c++;
		t = power(x , i) / fact(i);
		if(c % 2)
			cosx += t;
		else
			cosx -=t;
		i+=2;
		
	}
	printf("%.4lf\n" , cosx);
	return 0;
}
