/**Write a C function which moves the minimum element of the array at index 0, without removing any element of the array.

void minatzero(int a[], int len);*/
int a[8] = {4, 3, 5, 2}, len = 4;
movetozero(a, len);
printf("%d\n", a[0]);
void minatzero(int a[], int len){
	int swap;
	while(len > 0){
		if(a[len - 1] < a[0]){
			swap = a[0];
			a[0] = a[len - 1];
			a[len - 1] = swap;
		}
		len--;
	}
}
