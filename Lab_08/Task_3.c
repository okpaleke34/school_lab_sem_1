#include <stdio.h>
#include <stdlib.h>

const char* aster(int numb) {
    // reserve memory outside the local function scope
   char *batchOfAsters = malloc(sizeof(int) * 3);
    int i = 0;
    while (i != numb) {
        batchOfAsters[i] = '*';
        i++;
    }

    return batchOfAsters;
}

int main()
{

    printf("Takes a number of asters to be printed to the console from the user and generate it using aster(num) function.\n\n");
    int number;
    //accepting input from the user
    printf("Please enter an integer: ");
    scanf("%d",&number);

    printf("\n%s \n", aster( number));

    return 0;
}


