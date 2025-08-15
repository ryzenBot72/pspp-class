/**Write a C function which has header line given below, and which finds the maximum element in an array and returns it.

int findmax(int *arr, int len);*/
int findmax(int *arr, int len){
	int  i = 0;
	int max = 0;
	while(i < len){
		if(arr[i] > max)
			max = arr[i];
		i++;
	}
	return max;
}
