#include <stdio.h>
int main() {
	float p , r , y ;
	scanf("%f%f%f\n" , &p , &r , &y);
	float si = (p * r * y) /100;
	float total = p + si;
	printf("%.6f" , total);
	return 0;
}
