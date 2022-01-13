#include <string.h>
#include <stdio.h>
#include <ctype.h> 

int main()
{
    char userInput[] = "Some text input";
    // printf("Please enter some text: ");
    // fgets(userInput,100,stdin);
    int alphabet[26] = {0};
    int charInt;
    int arrSize = sizeof(userInput)/sizeof(userInput[0]);
    char character;
    
    for(int i = 0; i<arrSize -1 ; i++){
        
        //convert all the input to upper;
        character = toupper(userInput[i]);
        charInt = (int)(character) - 65;
        if(alphabet[charInt] == 0){
            alphabet[charInt] = 1;
        }
        else{
            alphabet[charInt] = alphabet[charInt] + 1;
        }
    }
    
    //Print occurance
    printf("\nThe occurance of different letters in the input are: \n");
    for(int i = 0; i < 26; i++){
        if(alphabet[i] > 0){
            printf("%c - %d \n", 65+i, alphabet[i]);
        }
    }
    return 0;
}
