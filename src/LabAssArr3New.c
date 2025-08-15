/**Write a C function that removes duplicates that occur equal to or more than k times, from a given array, which has data in unsorted order.

The function leaves only one copy of the k-times repeating numbers in the array.

function returns new length of the array.

int removedupl_k(int a[], int len, int k);*/
#include <stdio.h>
int removedupl_k(int a[], int len, int k){
	int rep[128];
	int pr[128];
	int i = 0, j = 0, c = 0 , d = 0;
	while(i < len){
		j = 0;
		c=0;
		while(j < len){
			if(a[i] == a[j])
				c++;
			j++;
		}
		j = 0;
		while(j < len){
			if(a[i] == pr[j]){
				rep[i] = 0;
				pr[i] = 0;
			}
			j++;
		}
		rep[i] = c;
		pr[i] = a[i];
		i++;
	}
	for(int i = 0;i < len;i++)
		printf("%d\n" , pr[i]);
	return len;
}
int main(){
	 int a[128] = {1, 1, 1, 2, 2, 2, 3, 3, 4, 5}; 
    int len = 10;
    len = removedupl_k(a, len, 2);
    /**for(int i = 0; i < len; i++) 
       printf("%d ", a[i]); 
    printf("\n");*/
    return 0;
}
