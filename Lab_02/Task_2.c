#include <stdio.h>
#include <stdlib.h>

int main()
{
    
    char *birthDate = "22-07-1999", *name = "Chukwudi", *surname = "Okpaleke";
    double PI = 22/7.;
    double quotient = 4/23.;

    printf("a. Birthday: %s\n",birthDate);
    printf("b. Name: %s %s\n",name,surname);
    printf("c. PI: %lf\n",PI);
    printf("d. Division of 4/23: %lf\n",quotient);
    

    return 0;
}
