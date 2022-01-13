#include <stdio.h>
#include <stdlib.h>

int main()
{
    char userInput[100];
    printf("This program takes a string input from a user and return the length without using strlen().\n\n");
    printf("Enter a string: ");
    scanf("%[^\n]%*c",&userInput);
    int count = 0;
    // loop through the characters till it gets to '\0' which marks the end of the file
    while(userInput[count] != '\0'){
        count++;
    }
    printf("The length of the entered input `%s` is  %d ",userInput,count);

}
