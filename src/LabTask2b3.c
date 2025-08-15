#include <stdio.h>
int main() {
	int a = 1, d = 2 , sum = 0 , n;
	scanf("%d\n" , &n);
	sum = ( 2 * a + ( n - 1 ) * d) * n / 2;
	printf("%d\n" , sum);
	return 0;
}
