#include <stdio.h>
int main() {
	int c1 , c2 , c3 , c4 , c5;
	int g1 , g2 , g3 , g4 , g5;
	scanf("%d%d%d%d%d%d%d%d%d%d\n" , &c1 , &g1 , &c2 , &g2 , &c3 , &g3 , &c4 , &g4 , &c5 , &g5);
	int tcp = (c1 * g1) + (c2 * g2) + (c3 * g3) + (c4 * g4) + (c5 * g5);
	int tc = c1 + c2 + c3 + c4 + c5;
	float sgpa = (float)tcp / tc;
	printf("%.6f\n" , sgpa);
	return 0;
}
