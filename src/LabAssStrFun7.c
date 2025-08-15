/**Write a C function to concatenate two strings.

char *strconcat(char *dest, const char *src);

The function appends src string at the end of dest string. The function assumes that dest has enough space for contatenation. The function returns the pointer to dest string.*/
#include <stdio.h>
char *strconcat(char *dest, const char *src){
	int c = 0;
	int d = 0;
	int i = 0;
	char *p;
	const char *q;
	q = src;
	p = dest;
	while(*p != '\0'){
		c++;
		p++;	
	}
	while(*q != '\0'){
		d++;
		q++;	
	}
	while(i < d){
		dest[c] = src[i];
		i++;
		c++;
	}
	return dest;
}
int main(){
char b[16] = "abhijit", a[16]="coep";
printf("%s\n", strconcat(b, a));
}
