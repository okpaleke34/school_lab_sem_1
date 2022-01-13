#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include <time.h>

#define randnum(min, max) \
        ((rand() % (int)(((max) + 1) - (min))) + (min))

//declaring the v3 struct
struct v3
{
    int x;
    int y;
    int z;
};



int calculate_length(int x, int y, int z){
    int length = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2) );
    return length;
}


int main()
{
    struct v3 arr[5];
    int i = 0;
    srand(time(NULL));   // Initialization, should only be called once.
    // fill the vectors with random values from 1-70
    for(i = 0; i < 5; i++){
        arr[i].x = randnum(1, 70);
        arr[i].y = randnum(1, 70);
        arr[i].z = randnum(1, 70);
    }

    int longest;
    //declare the initial vector as the longest
    longest = calculate_length(arr[0].x, arr[0].y, arr[0].z);
    int longest_vector = 0;
    for(i = 0; i < 5; i++){

        int length = calculate_length(arr[i].x, arr[i].y, arr[i].z);
        // if the current vector is bigger than the initial, overwrite it
        if(length > longest){
            longest = length;
            longest_vector = i;
        }
        printf("Vector: %d,  length =  %d\n",i, length);
    }

    printf("\n\n Longest Vector is Vector: %d\n",longest_vector);

    return 0;
}
