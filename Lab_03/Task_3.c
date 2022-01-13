
#include <stdio.h>
#include <math.h>

int main()
{
    //Defining variables and assigning values to it
    long long int n, i, j,divisor;
    n =  6321246989963LL;
    // Make a loop from 2 to the square root of the number n to check for a factor of n
    for(i = 2; i <= sqrt(n); i++)
    {
        //Check if result of the modulo operation is 0(hence it is a prime number)
        if(n % i == 0){
            printf("%I64d is not a Prime number. \nFactors of %I64d  are: 1",n);
            for (j = i; j <= sqrt(n); ++j) {
                if (n % j == 0) {
                    // Since we are checking for  numbers <= to the square root of the n variable, we cannot print all the factors
                    // So when we get a factor we divide it by n variable and print the quotient also
                    divisor = n/j;
                    printf(", %I64d, %I64d",j,divisor);
                }
            }
            printf(" and %I64d ",n);
            return 0;
        }
    }
    //It did not find any factor of the number( it is not a prime number)
    printf("%I64d is a prime number.", n);

    return 0;
}
