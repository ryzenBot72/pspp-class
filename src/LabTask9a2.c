/*Write a function that finds the maximum length substring of a given string(b) in another string (a) and returns a pointer to the first occurrence of the maximum length substring of b, in a.

char *strmaxstr(char *a, char *b);*/
#include <stdio.h>
#include <stdlib.h>
char *strmaxstr(char *a, char *b){
	char *p, *q;
	int len = 0,c , max = 0;
	char *pointer;
	p = a;
	q = b;
	while(*q != ' '){
		len++;
		q++;
	}
	while(*p != '\0'){
		c = 0;
		if(*p == *b){
			c = 1;
			for(int i = 1; i < len; i++){
				if(p[i] != b[i])
					break;
				else
					c++;
			}
		}
		if(c > max){
			pointer = p;
			max = c;
		}
		p++;
	}
	return pointer;
}
int main(){
	char *p;
	p = strmaxstr("abcee abcdm bdefg","abcdf");
	while(*p != '\0'){
		printf("%c" , *p);
		p++;
	}
	printf("\n");
	return 0;
}
