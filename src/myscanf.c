/*Write a version of your own scanf(), with simplified functionality.
Write a function that has this prototype
int myscanf(char *format, void *arg);
The function will be called like this:
int i; myscanf("%d", &i);
char ch; myscanf("%c", &ch);
char arr[4]; myscanf("%s", arr);
Handle these format specifiers: %d %f %lf %s %c %u */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int myscanf(char *format, void *arg){
	char ch;
	char *p;
	p = arg;
	int t = 0, c = 0, d = 0, count = 0, i = 0;
	float f = 0;
	double db = 0;
	switch (format[1]){
		case 'd':
			while((ch = getchar()) != '\n'){
				if(isspace(ch))
					continue;
				if((isdigit(ch) == 0) && ch != '-'){
					c++;
					break;
				}
				if((int)ch == 45){
					c++;
					continue;
				}
				t = (t * 10) + ((int)ch - 48);
				
			}
			if(c != 0)
				t = 0-t;
			*(int *)p = t;
			return 1;
		case 'f':
			while((ch = getchar()) != '\n'){
				if(isspace(ch))
					continue;
				if((isdigit(ch) == 0) && ch != '.' && ch != '-')
						break;
				if((int)ch == 45){
					c++;
					continue;
				}
				if((int)ch == 46){
					d = 0;
					count++;
					continue;	
				}
				f = (f * 10) + ((int)ch - 48);
				d++;
			}
			if(count != 0)
				while(d > 0){
					f = f/10;
					d--;
				}
			if(c != 0)
				f = 0-f;
			*(float *)p = f;
			return 1;
		case 'l':
			if(format[2] == 'f'){
				while((ch = getchar()) != '\n'){
					if(isspace(ch))
						continue;
					if((isdigit(ch) == 0) && ch != '.' && ch != '-')
						break;
					if((int)ch == 45){
						c++;
						continue;
					}
					if((int)ch == 46){
						d = 0;
						count++;
						continue;	
					}
					db = (db * 10) + ((int)ch - 48);
					d++;
				}
				if(count != 0)
					while(d > 0){
						db = db/10;
						d--;
					}
				if(c != 0)
					db = 0-db;
				*(double *)p = db;
				return 1;
			}
			else
				printf("INVALID DATA TYPE\n");
		case 's':
			while((ch = getchar()) != '\n' && ch != EOF){
				if(isspace(ch))
					continue;
				p[i] = ch;
				i++;
			}
			return 1;
		case 'c':
			*p = getchar();
			return 1;
		case 'u':
			while((ch = getchar()) != '\n'){
				if(isspace(ch))
					continue;
				if((unsigned int)ch == 45){
					c++;
					continue;
				}
				if((unsigned int)ch == 48){
					printf("INVALID DATA ENTRY\n");
					exit(1);
				}
				t = (t * 10) + ((unsigned int)ch - 48);
				
			}
			if(c != 0)
				t = 0-t;
			if(t == 0)
				break;
			*(unsigned int *)p = t;
			return 1;
		default:
			return 0;
	}
	return 0;
}
int main(){
 	

int i = 5; myscanf("%d", &i); printf("%d\n", i);
return 0;
}
