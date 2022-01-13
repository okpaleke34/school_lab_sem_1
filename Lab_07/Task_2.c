#include <stdio.h>
#include <stdlib.h>

//functions prototype
int gcd(int, int);
int custom_abs(int, int);

int main()
{
    int int1, int2 ;
    printf("This program takes two integers from the user and  find their least common multiple\n\n");


    printf("Please enter integer 1: ");
    scanf("%d",&int1);
    printf("Please enter integer 2: ");
    scanf("%d",&int2);
    int answer = custom_abs(int1,int2)/gcd(int1,int2);
    printf("The LCM of %d and %d is: %d",int1,int2,answer);

}
int custom_abs(int a, int b) {
    int product =  a * b;
     if(product < 0){
        return product * -1;
     }
     return product;
}
int gcd(int a, int b) {
    int count = 1;
    //continue running the loop if a is not equal to b
    while (a != b) {
        if (a > b) {
            int initA = a;
            a = a - b;
        }
        else if (a < b) {
            int initB = b;
            b = b - a;
        }
        else {
            break;
        }
        count++;
    }
    return b;
}
