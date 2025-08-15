/**Write a C function, with the prototype as given below, that returns the maximum absolute difference between any pair of adjacent numbers in an array.

Do NOT use the abs() function from stdlib.h

Assume that len >=2.

int maxabsdiff(int a[], int len);  // len is number of array elements.*/
#include <stdio.h>
int maxabsdiff(int a[], int len){
	int i = 1;
	int mdiff = 0;
	int diff;
	while(i < len){
		diff = a[i - 1] - a[i];
		if(diff < 0)
			diff = 0 - diff;
		if(diff > mdiff)
			mdiff = diff;
		i++;
	}
	return mdiff;
}
