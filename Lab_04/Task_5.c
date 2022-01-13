#include <math.h>
#include <stdlib.h>

int main()
{
    double y, r;
    int i= 0;
    y = 2;
    while(i < 1000){
        i++;
        r =  10 - pow(y,y);
        y = r < 1e-10? y - (0.5 / i): y + (0.5 / i);
    }
    printf("%.10f w=%f", pow(y,y), y);
    return 0;

}
