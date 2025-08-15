/**Write a C program that works as a continuously running calculator and evaluates expressions involving integers. The program takes input in the format

operand operator operand

where operand can be an integer, and operator can be any of these: + - *  / <<  >> %  | &  

and there can be any number of spaces in the input or any wrong characters can be typed.

The program terminates on end-of-input (control-D)

The program terminates, on any invalid input, and prints one of the following error messages (appropriately)

    printf("bad op1\n"); // when first operand as not given or bad

    printf("bad opr1\n");  // when first operator symbol was not given or bad
    printf("bad op2\n"); // when second operand was not given or bad
    printf("bad opr2\n"); // when second operator was not given
    printf("opr1 %c != opr2 %c\n", ...); // when second operator did not match expected first  operator*/
#include <stdio.h>
int main(){
	int op1 = 10000000, op2 = 10000000;
	char opr1, opr2 = 'a';
	while(scanf("%d" , &op1) != -1){
		if(op1 == 10000000){
			printf("bad op1\n");
			return 0;
			}
		scanf(" %c" , &opr1);
		if(opr1 == '<'){
			scanf("%c %d" ,&opr2 ,&op2);
		if(opr2 == '<')
			printf("%d\n" , op1 << op2);
		else if(opr2 == 'a'){
			printf("bad opr2\n");
			return 0;
			}
		else{
			printf("opr1 %c != opr2 %c\n", opr1 , opr2);
			return 0;
			}
		}
		else if(opr1 == '>'){
			scanf("%c %d" ,&opr2 ,&op2);
			if(opr2 == '>')
				printf("%d\n" , op1 >> op2);
			else if(opr2 == 'a'){
				printf("bad opr2\n");
				return 0;
				}
			else{
				printf("opr1 %c != opr2 %c\n", opr1 , opr2);
				return 0;
				}
		}
		else{
			scanf(" %d" , & op2);
			
			if(op2 == 10000000){
				printf("bad op2\n");
				return 0;
			}
			else{
				switch(opr1){
					case '+':
						printf("%d\n" , op1 + op2);
						break;
					case '-':
						printf("%d\n" , op1 - op2);
						break;
					case '*':
						printf("%d\n" , op1 * op2);
						break;
					case '/':
						printf("%d\n" , op1 / op2);
						break;
					case '%':
						printf("%d\n" , op1 % op2);
						break;
					case '|':
						printf("%d\n" , op1 | op2);
						break;
					case '&':
						printf("%d\n" , op1 & op2);
						break;
					default:
						printf("bad opr1\n");
						return 0;
						break;
				}
			}
		}
		op1 = 10000000;
	}
	return 0;
}
