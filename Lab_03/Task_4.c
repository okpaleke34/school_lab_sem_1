
#include <stdio.h>
#include <math.h>

int main()
{
    //Defining variables and assigning values to it
    int n,i;
    double t,x1,x0,xi;
    n = 1000;
    t = 0.001;
    x1 = n;
    xi = 1;
    while(abs(x0 - xi) > t){
        x0 = xi;
        xi = ((x1 /xi) + xi) / 2;
    }

    printf("The square root of %d using the tolerance level of %.3f is %f: ",n, t, xi);

    return 0;
}
