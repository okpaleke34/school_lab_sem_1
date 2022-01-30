#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    printf("This program finds the zeros in a linear function y = ax + b \n\n");
    int x = 1, a, i = 1;
    printf("Enter the value of a: ");
    scanf("%d", &a);
    for(; i <= a; ++i){
        x *= i;
    }
    printf("X = %d\n", x);


    return 0;
}
    
