#include <stdio.h>
int main() {
	int a, b , max;
	scanf("%d%d\n" , &a , &b);
	if(a > b){
		printf("%d\n" , a);
	} else if(b > a){
		printf("%d\n" , b);
	}else{
		printf("%d\n" , a);
	}
	return 0;
}
