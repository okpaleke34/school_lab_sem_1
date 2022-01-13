#include <math.h>
#include <stdlib.h>


int main()
{
	float a, b, c, d;
	float x1, x2, realPart, imaginaryPart;


	printf("This is a program that solves quadratic equation with the fomular ax^2 + bx + c  \n");
	printf("Please enter the value of a:");
	scanf_s("%f", &a);
	printf("Please enter the value of b:");
	scanf_s("%f", &b);
	printf("Please enter the value of c:");
	scanf_s("%f", &c);

	d = b * b - 4 * a * c;
	if (d < 0) {
		printf("Root is a complex number \n");
		realPart = -b / (2 * a);
        imaginaryPart = sqrt(-d) / (2 * a);
        printf("Root1 = %.2lf+%.2lfi and root2 = %.2f-%.2fi", realPart, imaginaryPart, realPart, imaginaryPart);
	}
	else if (d == 0) {
		x1 = -b / (2 * a);
		printf("Both roots are equal and root 1 = %.3f  and root 2 = %.3f", x1, x1);
	}
	else {
		x1 = (-b - sqrt(d)) / (2 * a);
		x2 = (-b + sqrt(d)) / (2 * a);
		printf("The roots are %.3f and %3.f ", x1, x2);
	}
	return 0;
}
