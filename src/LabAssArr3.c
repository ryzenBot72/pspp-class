/**Write a C function that removes duplicates that occur equal to or more than k times, from a given array, which has data in unsorted order.

The function leaves only one copy of the k-times repeating numbers in the array.

function returns new length of the array.

int removedupl_k(int a[], int len, int k);*/
#include <stdio.h>
int removedupl_k(int a[], int len, int k){
	int d[len], na[len];
	int c = 0 , di = 0, ni = 0, count = 0;
	for(int i = 0; i < len; i++){
		c = 0;
		count = 0;
		for(int l = 0; l < len; l++){
			if(a[i] == d[l])
				c++;
		}
		if(c != 0)
			continue;
		for(int j = 0; j < len; j++){
			if(a[i] == a[j]){
				count++;
			}
		}
		if(count >= k){
			d[di] = a[i];
			di++;
			na[ni] = a[i];
			ni++;
		}
		else{
			na[ni] = a[i];
			ni++;
		}
	}
	for(int i = 0; i < len; i++) 
		a[i] = na[i];
	len = ni;
	return len;
}
int main(){
int a[128] = {1,2,3};
    int len = 10;
    len = removedupl_k(a, len, 3);
    for(int i = 0; i < len; i++)
       printf("%d ", a[i]);
    printf("\n");
    return 0;
}
