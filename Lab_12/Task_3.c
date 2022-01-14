#include <stdio.h>
    

int main()
{
    
    char  buf[50];
    int a, b, k;
    
    printf("Enter and two numbers separated by space: ");
    
    fgets(buf,50,stdin);
    k = sscanf(buf,"%d %d",&a,&b);
    if(k == 2){
        printf("First number: %d\nSecond number: %d",a,b);
    }
    else{
        printf("There was a problem in your input, List of possible problems:\n\n1. You entered less than two inputs.\n2. One or both of the separeted inputs is not a number.");
    }

    return 0;
}
