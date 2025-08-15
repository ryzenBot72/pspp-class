/*Given that
1 ft = 12 inch
3 ft = 1 yd
1760 yd = 1 mile
 
Write a C program that reads input in the format of  a number, followed by a character (either f, or y or m representing feet, yard and mile respectively)  and converts it into inches and prints the output. The program prints "error" when there is error in input.
 
For example , input is:
2 y
Then the program outputs : 72 
(2 y = 6 ft = 72 inches)*/
#include <stdio.h>
int main() {
	int value , inches;
	char ch;
	scanf(" %d %c" , &value , &ch);
	switch(ch){
		case 'f':
			inches = value * 12;
			printf("%d\n" , inches);
			break;
		case 'y':
			inches = value * 3 * 12;
			printf("%d\n" , inches);
			break;
		case 'm':
			inches = value * 1760 * 3 * 12;
			printf("%d\n" , inches);
			break;
		default:
			printf("error");
			break;
	}
	
	return 0;
}
