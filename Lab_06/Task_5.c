#include <stdio.h>
#include <stdlib.h>

int factorial(int);

int main()
{
    int userInput;
    printf("This program takes an integer input from a user and return its factorial.\n\n");
    printf("Enter Integer less than 12 to get its factorial: ");
    scanf("%d",&userInput);
    if(userInput > 12)
        printf("This program cannot correctly calculate factorial of %d",userInput);
    else
        printf("Factorial of number %d is %d",userInput,factorial(userInput));
}

int factorial( int n)
{
    if (n > 1)
        return  n * factorial(n - 1);
    else
        return 1;
}
