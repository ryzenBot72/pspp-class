/*Write a program which reads two numbers, as month and date respectively.  For example, if the input is "2 3" then it means 3rd February.  Then the program prints the day-of-year corresponding to that date in a non-leap year.  So for input "2 3", the ouput will be "34" because 3rd Feb is 34th day-of-year (31 for Jan and 3 for Feb).

The program prints 0 on an invalid input.*/
#include <stdio.h>
int main() {
	int mon , date , days , zero = 0;
	scanf(" %d %d" , &mon , &date);
	switch(mon) {
		case 1:	//january
			if(date <= 31){
				days = date;
				printf("%d\n" , days);
			}else
				printf("%d\n",zero);
			break;
		case 2: //february
			if(date <= 28){
				days = 31 + date;
				printf("%d\n" , days);
			}else
				printf("%d\n",zero);
			break;
		case 3:	//march
			if(date <= 31){
				days = 59 + date;
				printf("%d\n" , days);
			}else
				printf("%d\n",zero);
			break;
		case 4:	//april
			if(date <= 30){
				days = 90 + date;
				printf("%d\n" , days);
			}else
				printf("%d\n",zero);
			break;
		case 5:	//may
			if(date <= 31){
				days = 120 + date;
				printf("%d\n" , days);
			}else
				printf("%d\n",zero);
			break;
		case 6:	//june
			if(date <= 30){
				days = 151 + date;
				printf("%d\n" , days);
			}else
				printf("%d\n",zero);
			break;
		case 7:	//july
			if(date <= 31){
				days = 181 + date;
				printf("%d\n" , days);
			}else
				printf("%d\n",zero);
			break;
		case 8: //august
			if(date <= 31){
				days = 212 + date;
				printf("%d\n" , days);
			}else
				printf("%d\n",zero);
			break;
		case 9: //september
			if(date <= 30){
				days = 243 + date;
				printf("%d\n" , days);
			}else
				printf("%d\n",zero);
			break;
		case 10: //october
			if(date <= 31){
				days = 273 + date;
				printf("%d\n" , days);
			}else
				printf("%d\n",zero);
			break;
		case 11: //november
			if(date <= 30){
				days = 304 + date;
				printf("%d\n" , days);
			}else
				printf("%d\n",zero);
			break;
		case 12: //december
			if(date <= 31){
				days = 334 + date;
				printf("%d\n" , days);
			}else
				printf("%d\n",zero);
			break;
		default:
			printf("%d\n",zero);
			break;
	}
	return 0;
}
