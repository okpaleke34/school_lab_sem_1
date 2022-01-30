#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    printf("This program finds the zeros in a linear function y = ax + b \n\n");
    float x, a, b;
    printf("Enter the value of a: ");
    scanf("%f", &a);
    printf("Enter the value of b: ");
    scanf("%f", &b);

    //giving y = ax + b and y = 0, a and b are user defined
    //then 0 = ax + b, multiply b by -1 to simulate taking it to the other side of the equation
    b = b * -1;
    // (-1)*b = ax
    //multiply both sides by 1/a to remove `a` from x side
    x = b/a;
    printf("x = %f\n", x );


    return 0;
}
    
