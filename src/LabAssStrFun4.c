/**Write a function with the given prototype. The function returns pointer to a malloced array,  after storing into the array the string containing digits representing the given numbers.

char *inttostring(int x);*/
#include <stdio.h>
#include <stdlib.h>
int power(int num ,int exp){
	int pr = 1;
	while(exp > 0){
		pr = pr * num;
		exp--;
	}
	return pr;
}
char *inttostring(int x){
	int ex = x, c = 0, i = 0, t;
	char *n;
	if(x == 0 || x == -0){
		n = (char *)malloc(sizeof(char *) * (2));
		n[0] = '0';
		return n;
	}
	if(ex < 0)
		ex = ex * -1;
	while(ex > 0){
		ex = ex / 10;
		c++;
	}
	n = (char *)malloc(sizeof(char *) * (c+1));
	if(x < 0){
		x = x * -1;
		n[i] = '-';
		i++;
	}
	ex = x;
	while(c > 0){
		t = ex / power(10 , c-1);
		n[i] = (char)(t+48);
		ex = ex % power(10 , c-1);
		c--;
		i++;
	}
	return n;
}
int main(){
char *p = inttostring(-23); printf("%s\n", p); free(p);
}
