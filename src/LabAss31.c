/*Write a program that reads a single character as input and checks if it's a vowel. 

A vowel  is one of the following characters, capital or small:  'a', 'e', 'i', 'o', 'u'

The program should print "vowel" or "not vowel".*/
#include <stdio.h>
int main() {
	char ch;
	scanf("%c" , &ch);
	if(ch == 'a' || ch == 'A' || ch == 'e' || ch == 'E' || ch == 'i' || ch == 'I' || ch == 'o' || ch == 'O' || ch == 'u' || ch == 'U')
		printf("vowel");
	else
		printf("not vowel");
	return 0;
}
