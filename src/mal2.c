/*Write a program that does the following :

   has one large array of size 1024 (or more)

    reads a number n from end user, then allocates an array of n character pointers (pointed to by say, p)

    then one by one, it reads n lines of input in the large array (upto its size) , but duplicates each string (with exact length) in a new malloced array every time,  and makes the pointer array elements point to it one by one

     then the program finds the line with the maximum length and prints it. (you can use strlen())

     The data when stored looks like this, and the output of the program will be : i love clang*/
#include <stdio.h>
#include <stdlib.h>
int main(){
	char line[2048];
	int n, i = 0, li = 0, j = 0, len = 0, uj;
	char **p, ch, *l;
	scanf("%d" , &n);
	p = (char **)malloc(sizeof(char **) * n);
	while(i < n){
		uj = j;
		len = 0;
		li = 0;
		ch = getchar();
		while(ch != '\n'){
			line[j] = ch;
			len++;
			j++;
			ch = getchar();
		}
		l = (char *)malloc(sizeof(char *) * len);
		for(int k = uj;k < j;k++){
			l[i] = line[k];
			li++;
		}
		p[i] = l;
		i++;
	}
	return 0;
}
