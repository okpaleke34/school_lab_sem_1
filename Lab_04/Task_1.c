#include <math.h>
#include <stdlib.h>

double f1(int x){
    return x <= 0? cbrt(abs(2 + x)): pow(x,2) + pow(M_E,2 * x);
}

double f2(int x){
    return 1 <= x && x <= 7? sqrt(abs(x)) + pow(M_E,(x/2) + 1): (2 * x) + ( (x - 2)/ (2 * pow(x,2) + 15));
}

int main()
{
    int x, funcType;
    printf("Which function do you want to use? Type 1 for function `1` or `2` for function 2: ");
    scanf_s("%d", &funcType);
    printf("Please enter the value of x: ");
    scanf_s("%d", &x);
    if(funcType == 1){
        printf("%lf",f1(x));
    }
    else{
        printf("%lf",f2(x));
    }
    return 0;
}
