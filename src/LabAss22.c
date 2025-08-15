#include <stdio.h>
int main() {
	int intPrice;
	float disc , finPrice;
	scanf("%d%f\n" , &intPrice , &disc);
	finPrice = intPrice - ((disc * intPrice)/100);
	printf("%.2f\n" , finPrice);
	return 0;
}
