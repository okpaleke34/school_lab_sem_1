#include <stdio.h>
/* To use the functions defined in Functions.c I need to #include Functions.h */
#include "Functions.h"


int main()
{
    //if the grades.csv file has not been created yet, it means it is running for the first time
    if(fileExists(GRADE_DB,0) == 0){
        printf("\nPlease if this is the first time of running the program, type `INFO` to get the information about the program and usage instruction.\n");
    }
    mainMenu();
    printf("\n\nThank you for using the program!!\n\n");
    return 0;
}
