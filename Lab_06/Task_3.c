#include <stdio.h>
#include <stdlib.h>
#define INPUTS 2

int retBigger(int, int);
int main()
{
    int userInput[INPUTS];
    printf("This program takes two integer input from a user and return the greater number.\n\n");
    for(int i= 0; i < INPUTS; i++){
        printf("Enter Integer %d: ",i+1);
        scanf("%d",&userInput[i]);
    }
    printf("%d is bigger than the other number",retBigger(userInput[1], userInput[2]));
}

int retBigger(int num1, int num2)
{
    if (num1 > num2)
    {
        return num1;
    }
    else{
        return num2;
    }
}
