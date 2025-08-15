/*Write  a C program which reads a number as a day-of-year (like 1, 2, .. 365).

The program then prints the month and date of that particular day-of-year, for the year 2023.*/
#include <stdio.h>
int main() {
	int day;
	scanf(" %d" , &day);
		if(day <= 31 && day > 0) { //january
			int one = 1;
			printf("%d %d" , day , one);
		}else if(day <= 59) { //february
			int two = 2;
			printf("%d %d" , (day - 31) , two);
		}else if(day <= 90) { //march
			int three = 3;
			printf("%d %d" , (day - 59) , three);
		}else if(day <= 120) { //april
			int four = 4;
			printf("%d %d" , (day - 90) , four);
		}else if(day <= 151) { //may
			int five = 5;
			printf("%d %d" , (day - 120) , five);
		}else if(day <= 181) { //june
			int six = 6;
			printf("%d %d" , (day - 151) , six);
		}else if(day <= 212) { //july
			int seven = 7;
			printf("%d %d" , (day - 181) , seven);
		}else if(day <= 243) { //august
			int eight = 8;
			printf("%d %d" , (day - 212) , eight);
		}else if(day <= 273) { //september
			int nine = 9;
			printf("%d %d" , (day - 243) , nine);
		}else if(day <= 304) { //october
			int ten = 10;
			printf("%d %d" , (day - 273) , ten);
		}else if(day <= 334) { //november
			int eleven = 11;
			printf("%d %d" , (day - 304) , eleven);
		}else if(day <= 365) { //december
			int twelve = 12;
			printf("%d %d" , (day - 334) , twelve);
		}else
			printf("invalid input");
	return 0;
}
