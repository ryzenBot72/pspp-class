#include <stdio.h>
int is_dupl(int a[], int len){
	int i;
	int j;
	int count = 0;
	int c = 0;
	for(i = 0; i < len; i++){
		count = 0;
		for(j = i + 1; j < len; j++){
			if (a[i] == a[j])
				count++;
		}
		if(count >= 1)
			c++;
	}
	return c;
}
int main() {
    int a[16], len;
    int i = 0;
    while(scanf("%d", &a[i]) != -1) {
        len++;
        i++;
    }
    printf("%d\n", is_dupl(a, len));
    return 0;
}
