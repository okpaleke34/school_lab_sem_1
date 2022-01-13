#include <stdio.h>

int main()
{

    //defining variables and assigning them to values
    int x,start,end;
    start = 32;
    end = 126;
    x = start;

    //use a do while loop to print the whole range
    do{
        printf("%d %c \n",x,x);
        x++;
    }
    while(x <= end);
    return 0;
}
