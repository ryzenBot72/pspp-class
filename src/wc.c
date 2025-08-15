/*Write a program that

reads a file, and prints the number of characters, words and lines in the file.

The filename is given as an input to the program from standard input (this is unlike the wc command)

$ ./mywc

/etc/passwd

68 119 4133 /etc/passwd

basically, the output of your program should be the same as the output of the Unix wc command.

You should separate all the fields in the output only with a single space, and should not use "alignment" as used by "wc" command.

 

Note: below 'data1.txt' (or so, mentioned in input) is a name of an input file. The input files can not be seen by you, but have been prepared and added to this question by the examiner. While testing your code on terminal, you need to enter the filename from standard input and read the filename using scanf() (or anything else).  */
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
void count(int fd, char *k, char *q){
	int c = 0;
	int w = 0;
	int l = 0;
	int flag = 0;
	while(read(fd,k,1)){
		c++;
		if(isspace(*k)){
			if(flag == 1){
				w++;
				flag = 0;
			}
		}
		else
			flag = 1;
		if(*k =='\n'){
			l++;
		}
		k++;
	}
	printf("%d %d %d %s\n" , l, w, c, q);
}
int main(){
	int fd;
	char filename[256];
	char *p;
	char add[256];
	scanf("%s" , filename);
	fd = open(filename, O_RDONLY);
	if (fd == -1) {
		printf("CAN'T OPEN FILE");
		exit(1);
	}
	p = filename;
	strcpy(add,filename);
	count(fd,p,add);
	close(fd);
	return 0;
}
