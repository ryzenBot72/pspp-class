#include <stdio.h>
int main(void)
{
	int n, i = 1, t = 1, sum = 0;

	scanf("%d", &n);
	printf("1");
	while (t <= n) {
		if (t % 2 != 0 && i != 1) {
			printf("+%d", i);
			sum += i;
		} else if (t % 2 != 0) {
			sum += i;
		} else {
			printf("-%d", i);
			sum -= i;
		}
		i = i + 2;
		t++;
	}
	printf("\n");
	printf("%d\n", sum);
	return 0;
}
