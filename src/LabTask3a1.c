#include <stdio.h>
int main() {
	int n;
	scanf("%d\n" , &n);
	if(n % 9 == 0){
		printf("multiple\n");
	} else {
		printf("not-multiple\n");
	}
	return 0;
}
