#include <stdio.h>
#include <stdlib.h>

const char* custom_strcat(char dest[50], char source[25]) {
   // get the length of the destination content
    int i = 0, j = 0;
    while (dest[i] != '\0') {
        i++;
    }

    //append source to the end of destination
    while (source[j] != '\0') {
        dest[i + j] = source[j];
        j++;
    }

    return dest;
}

int main()
{

    printf("This program takes two strings from the user and concatenate both of them using a custom strcat() fucntion.\n\n");
    char string1[50], string2[25], tempstring_1[25];
    //accepting input from the user
    printf("Please enter a string 1 less than 24 characters: ");
    scanf("%[^\n]%*c",&string1);
    printf("Please enter a string 2 less than 24 characters: ");
    scanf("%[^\n]%*c",&string2);
    //this copies string1 to tempstring_1 using the custom function
    custom_strcat(tempstring_1,string1);
    //This concatenate the two strings
    custom_strcat(string1, string2);
    printf("The concatenation of `%s` and `%s` is:  %s \n",tempstring_1, string2, string1);

    return 0;
}
