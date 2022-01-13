#include <stdio.h>
#include <stdlib.h>

double mulptiply_by_2(int *);

int main()
{

    int userInput;
    printf("This program takes an integer input from a user, get the pointer and double the dereferenced pointer.\n\n");
    printf("Please enter an integer: ");
    scanf("%d",&userInput);
    //getting the pointer address of the user input
    int* ptr  = &userInput;
    printf("The double is %.2lf",mulptiply_by_2(ptr));
}

double mulptiply_by_2(int *pointer){
    //dereferencing of the pointer and multiplying it by 2
    return (double)*pointer  * 2;
}
