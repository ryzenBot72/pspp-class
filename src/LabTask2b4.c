#include <stdio.h>
int main() {
	int a , d , sum = 0, n;
	scanf("%d%d%d" , &n , &a , &d);
	sum = ( 2 * a + ( n - 1 ) * d) * n / 2;
	printf("%d\n" , sum);
	return 0;
}
