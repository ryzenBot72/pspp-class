/**Write a function which compares two strings based on dictionary ordering, ignoring the case, and returns -1 if a is smaller than b, 0 if they are equal, and +1 if a is greater than b.

int strcasecompare(char *a, char *b); */
#include <stdio.h>
#include <ctype.h>
int strcasecompare(char *a, char *b){
	char *p, *q;
	int l = 0, m = 0, len, chara, charb;
	p = a;
	q = b;
	while(*p != '\0'){
		l++;
		p++;
	}
	while(*q != '\0'){
		m++;
		q++;
	}
	if(l < m)
		len = l;
	else
		len = m;
	for(int i = 0; i < len; i++){
		chara = a[i];
		charb = b[i];
		if(chara < charb)
			return -1;
		if(chara == charb)
			continue;
		if(chara > charb)
			return 1;
	}
	return 0;
}
int main(){
	char *a = "hi", *b = "hi";
printf("%d\n", strcasecompare(a, b));
}
