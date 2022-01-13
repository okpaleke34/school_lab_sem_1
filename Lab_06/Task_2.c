#include <stdio.h>
#include <stdlib.h>


int main()
{
    //defining double of numbers
    double num1 = 1.0;
    double num2 = 2.0;
    double num3 = 3.0;
    double num4 = 4.0;
    double num5 = 5.0;

    //getting pointers from the doubles
    double* p_num1 = &num1;
    double* p_num2 = &num2;
    double* p_num3 = &num3;
    double* p_num4 = &num4;
    double* p_num5 = &num5;
    //filling an array using the pointers
    double arr[] = {*p_num1,*p_num2,*p_num3,*p_num4,*p_num5};
    
    //printing the content of the array using indexing
    for(int i = 0; i < 5; i++){
        printf("%.2f \n",*(arr + i) );
    }

}
