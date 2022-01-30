#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<time.h>

void sixOfFortyNine();
void sixOfFortyNine_Unique();

int main()
{


    // This function will generate unique numbers every time the function is run
    printf("This function will generate unique numbers every time the function is run.\n\nFirst Time: ");
    sixOfFortyNine_Unique();
    printf("\nSecond Time: ");
    sixOfFortyNine_Unique();
    printf("\n\n");

    //This function will give exact number of 39,27,22,37,36,38 after each build and run
    printf("This function will give exact number of 39,27,22,37,36,38 after each build and run.\n\n");
    sixOfFortyNine();
    printf("\n\n");

    return 0;
}

void sixOfFortyNine(){
    int total = 6;
    //this sets the random generator to a static point of 0, making the rand() to return same number after build and run
    srand(0);
    for(int i = 1; i <= total; ++i){
        printf("%d", rand() % 49 + 1);
        if(i != total){
                printf(",");
        }
    }
}

void sixOfFortyNine_Unique(){
    //this sets the random generator to random number from 0-9999 * time(NULL), making the rand() to return different number any time the function is run
    srand(rand() % 10000 * time(NULL));
    int total = 6;
    for(int i = 1; i <= total; ++i){
        printf("%d", rand() % 49 + 1);
        if(i != total){
                printf(",");
        }
    }
}

    
