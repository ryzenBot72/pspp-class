/**Write a C function that has header line given below, and which finds the number that repeats the maximum times in a given array.  If there are multiple such numbers, then it returns the number that appears farthest from index 0 in the array.

int max_repeated(int *arr, int len); // len is no of elements in array*/
int max_repeated(int *arr, int len){
	int i = 0;
	int j = 0;
	int c = 0;
	int max = 0;
	int maxnum;
	while(i < len){ //the outer loop that changes the number we are checking
		c = 0;
		while(j < len){//the inner loop that checks the number with each term
			if(arr[i] == arr[j])
				c++;
			j++;
		}
		if(c >= max)
			maxnum = arr[i];
		i++;
	}
	return maxnum;
}
