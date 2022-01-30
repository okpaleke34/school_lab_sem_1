#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    //These two operation returns "-1.#IND00" in windows OS which stands for Indeterminate, in Linux OS it returns "NaN" which means Not a Number
    //It is a kind of Out of range exception in C 
    printf("\nThese two operation returns \"-1.#IND00\" in windows OS which stands for Indeterminate, in Linux OS it returns \"NaN\" which means Not a Number\n");


    printf("sqrt(-4): %f \n\n",sqrt(-4));

    printf("asin(7): %f \n\n",asin(7));

    
    return 0;
}
    
