/**Write a C function that  returns the factorial of a given unsigned integer.

unsigned long factorial(unsigned int)*/
unsigned long int factorial(unsigned int n){
	int fact = 1;
	while(n >= 1){
		fact *= n;
		n--;
	}
	return fact;
}
