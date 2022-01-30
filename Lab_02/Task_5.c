#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("A program that prints ASCII characters and their values from 0 - 100 \n\n");
    printf("Int Specifier       Char specifier\n");
    for(int i = 0; i <= 100; i++){
        printf("%*d  %c\n",-20,i,i );
    }
    return 0;
}
    
