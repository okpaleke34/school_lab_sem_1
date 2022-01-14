#include "function.h"

void getInput()
{
    char  buf[75];
    int a, b,c, k;

    printf("Enter and three numbers separated by space: ");

    fgets(buf,75,stdin);
    k = sscanf(buf,"%d %d %d",&a,&b,&c);
    //`k` varaiable returns the number of allowed data types entered by the user. 
    //Assuming the user entered 1 integer and  2 strings it will return 1
    if(k == 3){
        printf("The minimum number in %d,%d and %d is: %d",a,b,c,MIN(a,b,c));
    }
    else{
        printf("There was a problem in your input, List of possible problems:\n\n1. You entered less than three inputs.\n2. One or more of the inputs is not a number.");
    }
}
