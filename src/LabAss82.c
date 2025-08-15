/**Write a C function that has a prototype given below, and which finds the second maximum number in a given array.

If array length is 1, then it returns INT_MIN;

int second_max(int *arr, int len); // len is no of elements in array*/
#include <stdio.h>
#include <limits.h>
int second_max(int *arr, int len){
	int max = INT_MIN;
	int smax = 0;
	int i = 0;
	if(len == 1)
		return max;
	while(i < len){
		if(arr[i] >= max){
			smax = max;
			max = arr[i];
		}
		else if(arr[i] < max && arr[i] > smax){
			smax = arr[i];
		}
		i++;
	}
	return smax;
}
