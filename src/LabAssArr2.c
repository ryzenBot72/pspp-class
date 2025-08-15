/**Write a C function to reverse an array.

void reverse(int a[], int len);*/
void reverse(int a[], int len){
	int i = 0;
	int swap;
	while(i < (len/2)){
		swap = a[i];
		a[i] = a[len - 1 - i];
		a[len - 1 - i] = swap;
		i++;
	}
}
