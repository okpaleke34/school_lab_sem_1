#include <stdio.h>
#include <stdlib.h>

//functions prototype
int gcd(int, int);

int main()
{
    int int1, int2 ;
    printf("This program takes two integers from the user and  find their greatest common divisor  using a function gcd(int1,int2).\nIf a > b, it will perform the operation a = a - b while if b > a, it will assign b to the difference between b and a \n\n");


    printf("Please enter integer 1: ");
    scanf("%d",&int1);
    printf("Please enter integer 2: ");
    scanf("%d",&int2);
    gcd(int1,int2);

}

int gcd(int a, int b) {
    int count = 1;
    //continue running the loop if a is not equal to b
    while (a != b) {
        if (a > b) {
            int initA = a;
            a = a - b;
            printf("Step %d: a = %d, b = %d: Operation a = a - b \n-New a = %d  \n", count, initA, b, a);
        }
        else if (a < b) {
            int initB = b;
            b = b - a;
            printf("Step %d: a = %d, b = %d: Operation b = b - a \n-New b = %d \n", count, a, initB, b);
        }
        else {
            break;
        }
        count++;
    }
    printf("\n\nAnswer =  a: %d; b: %d \n\n", a, b);
    return 0;
}
