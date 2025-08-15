/**Write a C function that returns a pointer to the first occurrence of the character c in the string s, or NULL if the character is not found. The  terminating  NUL  byte is considered part of the string, so that if c is specified as '\0', these functions return a pointer to the terminator.

char *strchar(char *str, char c);

For example if str is "abhijit" and c is 'h' then a pointer to 'h' in "abhijit" will be returned.*/
#include <stdio.h>
char *strchar(char *s, char c){
	char *n;
	while(*s != '\0'){
		if(*s == c){
			n = s;
			return n;
		}
		s++;
	}
	n = NULL;
	if(c == '\0')
		n = s;
	return n;
}
int main(){
printf("%s\n", strchar("abhijit", 'h'));
	return 0;
}
