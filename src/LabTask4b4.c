/**Write a C program that reads characters one after another, and for each character prints if it is a vowel or not.*/
#include <stdio.h>
int main() {
	char ch;
	do{
		scanf("%c", &ch);
		if(ch == 'A' || ch == 'a' || ch == 'E' || ch == 'e' || ch == 'I' || ch == 'i' || ch == 'O' || ch == 'o' || ch == 'U' || ch == 'u')
			printf("vowel\n");
		else
			printf("not-vowel\n");
	}
	while(ch != '\n');
	return 0;
}
