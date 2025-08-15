#include <stdio.h>
int main() {
	int a , b , c;
	float avg;
	scanf("%d%d%d\n" , &a , &b , &c);
	avg = (float)(a+b+c) / 3;
	printf("%.2f\n" , avg);
	return 0;
}
