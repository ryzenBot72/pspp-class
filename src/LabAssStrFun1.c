/**Write a C function that returns a pointer to a new string which is a duplicate of the string s.  Memory for the new string is  obtained  with  malloc(), and can be freed with free() by the caller.
char *strdupl(const char *s);*/
#include <stdio.h>
#include <stdlib.h>
char *strdupl(const char *s){
	char *n;
	int i = 0;
	n = (char *)malloc(sizeof(char *)* 5);
	const char *p;
	p = s;
	while(*p != '\0'){
		n[i] = s[i];
		p++;
		i++;
	}
	return n;
}
int main(){
	char *str = "hello", *p;
	p = strdupl(str); 
	printf("%s\n", p);
	free(p);
}
