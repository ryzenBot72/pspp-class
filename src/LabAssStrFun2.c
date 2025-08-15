/**Write a function stringtoint() with the given prototype. The function converts the sequence of digits (found until NUL or a non-digit character) and returns the integer equivalent of it.

Function returns 0 if there is no digit character in the given string. Handle negative numbers as well.

long stringtoint(char *str);*/
#include <stdio.h>
long stringtoint(char *str){
	int c = 0, count =0;
	int t;
	int ans = 0;
	char *p;
	p = str;
	while(*p != '\0'){
		c++;
		p++;
	}
	for(int i = 0 ; i < c ; i++){
		if((int)str[i] > 57)
			continue;
		if((int)str[i] == 45 && i == 0){
			count++;
			continue;
		}
		t = ((int)str[i]) - 48;
		ans = (ans * 10) + t;
	}
	if(count != 0)
		ans = ans * -1;
	return ans;
}
int main(){
	 printf("%ld\n", stringtoint("345a"));
}
