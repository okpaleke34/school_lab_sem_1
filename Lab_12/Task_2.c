#include <stdio.h>
#include <string.h>
#define MIN_1(V,W) \
        ((V) < (W)?(V):(W))
#define MIN(X,Y,Z) \
        (MIN_1(X,Y) < (Z)?MIN_1(X,Y):(Z))
    

int main()
{
    
    char  buf[75];
    int a, b,c, k;
    
    printf("Enter and three numbers separated by space: ");
    
    fgets(buf,75,stdin);
    k = sscanf(buf,"%d %d %d",&a,&b,&c);
    if(k == 3){
        printf("The minimum number in %d,%d,%d is: %d",a,b,c,MIN(a,b,c));
    }
    else{
        printf("There was a problem in your input, List of possible problems:\n\n1. You entered less than three inputs.\n2. One or more of the inputs is not a number.");
    }

    return 0;
}
