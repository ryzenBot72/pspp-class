#include <stdio.h>
int main() {
	double foot , milli;
	scanf("%lf\n" , &foot);
	milli =  foot * 304.8 ; 
	printf("%.2lf" , milli);
	return 0;
}
