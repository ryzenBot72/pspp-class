/**Write a C function that checks if a given array is in non-descending order or not. Function returns 1 if true, and 0 if false.

int is_non_descending(int *a, int len);*/
int is_non_descending(int *a, int len){
	int i = 0;
	int c = 0;
	if(len == 1 || len == 0)
		return 1;
	while(i < (len-1)){
		if(a[i] <= a[i+1])
			c++;
		else
			return 0;
		i++;
	}
	return 1;
}
