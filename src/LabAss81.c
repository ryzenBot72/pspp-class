/**Write a C program which reads a sequence of numbers in an array. Then in one pass over the array (that is one single loop that examines each array element only once), the program finds out the maximum number, and number of repetitions of that number.*/
#include <stdio.h>
int main(){
	int n[100];
	int l = 0;
	int c = 0;
	int max = 0;
	
	//accepting the array
	while(scanf("%d" , &n[l]) == 1){
		l++;
	}
	
	
	//printing
	while(l > 0){
		if(n[l - 1] > max){
			max = n[l - 1];
			c = 1;
			l--;
		}
		else if(n[l - 1] == max){
			c++;
			l--;
		}
		else
			l--;
	}
	printf("%d %d\n" , max , c);
	return 0;
}
