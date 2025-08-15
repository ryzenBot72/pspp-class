#include <stdio.h>
int main() {
	float invest , sales ;
	scanf("%f%f\n" , &invest , &sales);
	if( (sales - invest) > 0){
		float profit = ((sales - invest)/invest) * 100;
		printf("profit: %.2f%%\n" , profit);
	} else if ( (invest - sales) > 0){
		float loss = ((invest - sales)/invest) * 100;
		printf("loss: %.2f%% \n" , loss);
	} else {
		printf("no-profit, no-loss");
	}
	return 0;
}
