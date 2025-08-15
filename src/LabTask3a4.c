#include <stdio.h>
int main() {
	int year;
	scanf("%d\n" , &year);
	if( year % 4 == 0 && year % 100 != 0){
		printf("leap");
	}else if ( year % 400 == 0){
		printf("leap");
	}else{
		printf("not-leap");
	}
	return 0;
}
