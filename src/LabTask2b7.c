#include <stdio.h>
int main() {
	double radius, perimeter;
	const double pi = 3.1415;
	scanf("%lf\n" , &radius);
	perimeter = 2 * pi * radius;
	printf("%.2lf\n" , perimeter);
	return 0;
}
