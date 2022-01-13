
#include <stdio.h>
#include <math.h>


int main()
{
    int i,y;
    y = 2;

    printf("Please enter a number: ");
    // Accepting input from user and assign it to variable i
    scanf_s("%d", &i);
    // print the input to append to last statment after the execution
    printf("%d",i);
    //loop through number less than or equal to the square root of the input
    while(y < sqrt(i))
    {
        //check if the result of any modulo operation is  equal to 0
        if(i%y == 0)
        {
            printf(" is not a prime number");
            return 0;
        }
        y++;
    }
    printf(" is a prime number");

    return 0;

}
