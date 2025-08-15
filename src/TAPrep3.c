#include <stdio.h>
#include <math.h>
int main() {
	int a = 10, b = 20 , c = 30;
	int d;
	
	d = a && b | b && c;
	printf("%ls\n" , &d);
	return 0;
}
