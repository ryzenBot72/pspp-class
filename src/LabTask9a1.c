/*Write a function that locates a given string (b) as a substring in another string (a), and returns a pointer to the first occurrence of b, in a.

char *strstr(char *a, char *b);

e.g. if  a is "abhijit is here" and b is "is" , then the function returns a pointer to "i" of "is" in a*/
#include <stdio.h>
#include <stdlib.h>
char *strstr(char *a, char *b){
	char *p, *q;
	char *n = '\0';
	int len = 0,c;
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
		if(c == len)
			return p;
		p++;
	}
	return n;
}
int main(){
	char *p;
	p = strstr("deepali mahadik","had");
	if(*p == '\0'){
		printf("NOT FOUND");
		exit(1);
	}
	while(*p != '\0'){
		printf("%c" , *p);
		p++;
	}
	printf("\n");
	return 0;
}
