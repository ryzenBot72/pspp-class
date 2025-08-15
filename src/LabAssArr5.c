/**Write a C function that removes duplicates that occur equal to or more than k times, from a given array, which has data in sorted order.

The function leaves only one copy of the k-times repeating numbers in the array.

function returns new length of the array.

int removedupl_k(int a[], int len, int k);*/
#include <stdio.h>
int removedupl_k(int a[], int len, int k){
	int i = 0, j, c = 0, ni=0,count =0, n;
	int na[128];
	int nlen=0;
	while(i < len){ //choosing one element to check
		count = 0;
		n = nlen;
		while((n-1) >= 0){
			if(na[n-1] == a[i])
				count++;
			n--;
		}
		if(count!=0){
			i++;
			continue;
		}
		c = 1;
		j = i + 1;
		while(j < len){ //counting the repetitions
			if(a[i] == a[j])
				c++;
			j++;
		}
		if(c >= k){
			na[ni] = a[i];
			ni++;
			nlen++;
		}
		else{
			while(c > 0){
				na[ni] = a[i];
				c--;
				ni++;
				nlen++;
			}
		}
		i++;
	}
	for(int i = 0; i < nlen; i++) 
		a[i] = na[i];
	return nlen;
}
int main(){
	 int a[128] = {1, 1, 1, 2, 2, 2, 3, 3, 4, 5}; 
    int len = 10;
    len = removedupl_k(a, len, 2);
    for(int i = 0; i < len; i++) 
       printf("%d ", a[i]); 
    printf("\n");
}
