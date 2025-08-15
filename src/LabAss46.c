#include <stdio.h>
int main()
{
	int a, b, c = 0, i = 0, prev = 0, curr = 1, next;
	scanf("%d%d", &a, &b);
	while (i <= 50) {
		next = curr + prev;
		if (a == curr && b == next) {
			c++;
			break;
		}
		prev = curr;
		curr = next;
		i++;
	}
	if (c == 0)
		printf("no\n");
	else
		printf("yes\n");
	return 0;
}
