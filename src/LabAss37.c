#include <stdio.h>
int main()
{
	char shape, op;
	double area, peri, side = 0, height = 0, base = 0, radius = 0, length = 0, breadth = 0, side1 = 0, side2 = 0, side3 = 0;
	scanf(" %c %c", &shape, &op);
	switch(shape) {
	case 't':
		if (op == 'a') {
			scanf(" %lf %lf" , &base, &height);
			if (base == 0 || height == 0)
				printf("error");
			else {
				area = 0.5 * base * height;
				printf("%.2lf" , area);
			}
		}else if (op == 'p') {
			scanf(" %lf %lf %lf" , &side1, &side2, &side3);
			if (side1 == 0 || side2 == 0 || side3 == 0)
				printf("error");
			else {
				peri = side1 + side2 + side3;
				printf("%.2lf" , peri);
			}
		}else
			printf("error");
		break;
	case 'r':
		scanf(" %lf %lf" , &length, &breadth);
		if (op == 'a') {
			if (length == 0 || breadth == 0)
				printf("error");
			else {
				area = length * breadth;
				printf("%.2lf" , area);
			}
		}else if (op == 'p') {
			if (length == 0 || breadth == 0)
				printf("error");
			else {
				peri = 2 * (length + breadth);
				printf("%.2lf" , peri);
			}
		}else
			printf("error");
		break;
	case 's':		
		scanf(" %lf" , &side);
		if (op == 'a') {
			if (side == 0)
				printf("error");
			else {
				area = side * side;
				printf("%.2lf" , area);
			}
		}else if (op == 'p') {
			if (side == 0)
				printf("error");
			else {
				peri = 4 * side;
				printf("%.2lf" , peri);
			}
		}else
			printf("error");
		break;
	case 'c':	
		scanf(" %lf" , &radius);
		if (op == 'a') {
			if (radius == 0)
				printf("error");
			else {
				area = 3.14 * radius * radius;
				printf("%.2lf" , area);
			}
		}else if (op == 'p') {
			if (radius == 0)
				printf("error");
			else {
				peri = 2 * 3.14 * radius;
				printf("%.2lf" , peri);
			}
		}else
			printf("error");
		break;
	default:
		printf("error");
	}
	return 0;
}
