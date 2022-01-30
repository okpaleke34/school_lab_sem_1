#include <stdio.h>
#include <time.h>
    
    
    int main()
    {
    
        clock_t t;
        t = clock();
        
        long int emptyLoopCount = 0, floatMultiplyCount = 0, floatDivisionCount = 0;
        while(clock() - t <= 1000){
            emptyLoopCount++;
        }
        printf("%d counts can be done in an empty loop in 1 seconds(1000 milliseconds)\n",emptyLoopCount);
    
        t = clock();
        //This will exist the loop at exactly 1 second
        while(clock() - t <= 1000){
            float x = (float)rand()/(float)(rand() % 100);
            float y = (float)rand()/(float)(rand() % 100);
            float product = y * x;
            floatMultiplyCount++;
        }
        printf("%d  random floating point multiplications can be done in 1 seconds(1000 milliseconds)\n",floatMultiplyCount);
    
        
    
        t = clock();
        //This will exist the loop at exactly 1 second
        while(clock() - t <= 1000){
            float x = (float)rand()/(float)(rand() % 100);
            float y = (float)rand()/(float)(rand() % 100);
            float quotient = y / x;
            floatDivisionCount++;
        }
        printf("%d  random floating point division can be done in 1 seconds(1000 milliseconds)\n",floatDivisionCount);
        return 0;
    }
    
