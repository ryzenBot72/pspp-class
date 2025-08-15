/*Write a C program that checks if a given character is a small alphabet ('a'..'z') or capital alphabet      		 ('A'..'Z') or a digit ('0'..'9') or other.
 The output of the program should be "small" or "capital" or "digit" or "other".
*/
#include <stdio.h>
int main() {
	char ch;
	scanf("%c" , &ch);
	if(ch >= 65 && ch <= 90)
		printf("capital");
	else if(ch >= 97 && ch <= 122)
		printf("small");
	else if(ch >= 48 && ch <= 57)
		printf("digit");
	else
		printf("other");
	return 0;
}
