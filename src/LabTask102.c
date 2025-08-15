/*Write a program that reads n (that is number of records to be read)
   then reads sequence of n structs given below in an array
   then prints the array of structs,
    then reads an index and another struct
    then inserts the newly read struct in the array in the given index position (by shifting other structs to left or right)
    then prints the whole array again.
struct point {int x, y, z};*/
#include <stdio.h>
typedef struct point{
	int x, y, z;
}point;
void insertpt(int new,int x,int y,int z,int n, point a[20]){
	for(int i = n-1; i >= new;i--){
		a[i+1].x = a[i].x;
		a[i+1].y = a[i].y;
		a[i+1].z = a[i].z;
	}
	a[new].x = x;
	a[new].y = y;
	a[new].z = z;
}
int main(){
	int n, i = 0, new, nx, ny, nz;
	scanf("%d" , &n);
	point a[20];
	for(int i = 0; i < n;i++)
		scanf("%d %d %d" , &a[i].x , &a[i].y , &a[i].z);
	printf("----array----\n");
	scanf("%d %d %d %d" , &new, &nx, &ny, &nz);
	insertpt(new, nx, ny, nz, n, a);
	printf("----array----\n");
	for(int j = 0; j <= n; j++)
		printf("%d %d %d\n", a[j].x , a[j].y , a[j].z);
}
