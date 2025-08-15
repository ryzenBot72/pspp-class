/**Suppose the following function is available to your code

int add(int a, int b) {

  return a + b;

}

then write a function

int mult(int x, int y);

which multiplies the two numbers x and y, and returns the result, but without using * operator, and rather using the calls to the function add(). */
int add(int a, int b) {

  return a + b;

}
int mult(int x, int y){
	int sum = 0;
	int c = 0;
	if(x < 0){
		while(x < 0){
			sum = add(sum , y);
			c++;
			x++;
		}
	}
	else{
		while(x > 0){
			sum = add(sum , y);
			x--;
		}
	}
	if(c == 0)
		return sum;
	else
		return (0 - sum);
}

