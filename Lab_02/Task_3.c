#include <stdio.h>
    #include <stdlib.h>
    #include <math.h>
    
    int main()
    {
        int b =2;
        float x, a1, a2, a3, a4, c = 3.5;
        float oneFifth = 1/5.;
        double PI = 3.14159265359;
    
        printf("Enter the value of x: ");
        scanf("%f", &x);
    
        // evaluating the sum of square of 3.5 and 2
        a1 = sqrt(pow(b,2) + pow(c,2));
        printf("a. a1 = %f\n", a1 );
    
        a2 = 15 + pow(b,3) - (3 * pow(c,2) ) + ((1/3.) * x);
        printf("b. a2 = %f\n", a2 );
    
        a3 = (x - 2) /(4 * pow(b,2) ) + 2 * c;
        printf("c. a3 = %f\n", a3 );
    
        //convert x from radians to degree
        double sinx = sin(x * (PI / 180.0) );
        a4 = (2 * sinx) - (4 * pow(b,2) ) + ((1/3.) * c);
        //if the result is a negative then let cmplx be `i`
        char cmplx = a4 < 0?'i':' ';
        //find the fifth root of the absolute value of the result
        a4 = pow(abs(a4), oneFifth);
    
        printf("d. a4 = %f%c\n", a4,cmplx );
    
        return 0;
    }

    
