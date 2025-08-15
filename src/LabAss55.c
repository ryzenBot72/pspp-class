/**Write a function that checks if a given integer is odd.

The function should take care of negative numbers also (read more about this)

int isodd(int x); //returns 1 if odd, and  if even*/
#include <stdio.h>
int isodd(int x){
	if(x % 2 == 0)
		return 0;
	else
		return 1;
}
int main(){
	printf("%d\n", isodd(-1));
}
