#include <stdio.h>
double power(double x, int n)
{
	double pr = 1;

	while ((double)n > 0.000000) {
		pr *= x;
		n--;
	} return pr;
}

int fact(int n)
{
	int f = 1;

	while ((double)n > 0.000000) {
		f *= n;
		n--;
	} return f;
}

int main(void)
{
	double x, ans;
	int n;

	scanf("%lf%d", &x, &n);
	ans = power(x, n) / fact(n);
	printf("%.2lf\n", ans);
	return 0;
}
