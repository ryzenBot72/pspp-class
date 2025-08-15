#include <stdio.h>
#include <math.h>
int main() {
	float a , b , c;
	float r1 , r2;
	scanf("%f%f%f\n" , &a , &b , &c);
	float D = (b * b) - (4 * a * c);
	if(D < 0 || a == 0){
		printf("can't find roots\n");
	} else {
		r1 = (-b + sqrt(D))/(2 * a) ;
		r2 = (-b - sqrt(D))/(2 * a) ;
		printf("%.6f %.6f\n" , r1 , r2);
	}
	return 0;
}
