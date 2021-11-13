
#include <stdio.h>
#include <ctype.h> 
#define S 100

int main()
{
    //set all the array to 0
    char userInput[S] = {0};
    printf("Please enter some text: ");
    //take input till there is new line, this will help to include text after space
    scanf("%[^\n]%*c", userInput);
    int alphabet[26] = {0};
    int charInt;
    char letter;
    for(int i = 0; i< S -1 ; i++){
        if(((int)userInput[i] >= 65 && (int)userInput[i] <= 90) || ((int)userInput[i] >= 97 && (int)userInput[i] <= 122)){
            //convert all the input to upper;
            letter = toupper(userInput[i]);
            //remove 65 from the int equivalent to reduce all to index of 0
            charInt = (int)(letter) - 65;
            
            if(alphabet[charInt] == 0){
                alphabet[charInt] = 1;
            }
            else{
                alphabet[charInt] = alphabet[charInt] + 1;
            }
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
