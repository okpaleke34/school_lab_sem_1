#include <stdio.h>
#include <stdlib.h>

int main()
{


    char userInput;
    char arr[100];
    printf("Enter a line of text: \n\n");
    int s = 0;
    for(int i = 0; i < 100; i++)
    {
        userInput = getchar();
        if(userInput == EOF)
            break;
        arr[i] = userInput;
    }

    int count = 0;
    while(arr[count] != '\0'){
        putchar(arr[count]);
        count++;
    }

    printf("\n\n");

    count = 0;
    while(arr[count] != '\0'){
        putchar(arr[count]);
        count++;
    }

}
