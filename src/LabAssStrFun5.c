/**Write the following C function.

    char *stranybyte(const char *s, const char *accept);
              Return a pointer to the first occurrence in the string s of one of the bytes in the string accept, or NULL if no such byte is found.

For example if s is "abhijit" and accept is "xiy" then  the function returns a pointer to the first occurrence of 'i' in abhijit (because 'x' and 'y' do not appear in "abhijit")

For example if s is "abhijit" and accept is "ta" then  the function returns a pointer to first occurrence of 'a' in abhijit (although both 't' and 'a' appear, 'a' appears first in s string)*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *stranybyte(const char *s, const char *accept){
	const char *p , *q ;
	char *n, *k;
	char Nul = '\0';
	int c = 0;
	char ch = '1';
	int i = 0, j = 0;
	int l = 0, m = 0;
	p = s;
	q = accept;
	extern char *strdup(const char*);
	while(*p != '\0'){
		l++;
		p++;
	}
	while(*q != '\0'){
		m++;
		q++;
	}
	while(i < l){
		j = 0;
		while(j < m){
			if(s[i] == accept[j]){
				ch = s[i];
				c++;
				break;
			}
			j++;
		}
		if(ch != '1')
			break;
		i++;
	}
	n =(char *)(strdup(s));
	while(*n != '\0'){
		if(*n == ch){
			k = n;
			break;
		}
		n++;
	}
	if(c == 0){
		k = &Nul;
		return k;
	}
	return k;
}
int main(){
	printf("%s\n", stranybyte("abhijit","xiy") ? stranybyte("abhijit","xiy"): "");
	return 0;
}
