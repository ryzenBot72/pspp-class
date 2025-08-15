/**Write a C function that checks if a given character is a digit or not.

int isadigit(char ch);

//returns 1 if ch is digit, returns 0 otherwise*/
int isadigit(char ch){
	if(ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch == '6' || ch == '7' || ch == '8' || ch == '9' || ch == '0')
		return 1;
	else
		return 0; 
}
