#include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <time.h>
    
    #define randnum(min, max) \
            ((rand() % (int)(((max) + 1) - (min))) + (min))
    
    int main()
    {
        FILE* file;
    
        srand(time(NULL));   // Initialization, should only be called once.
        char file_path[50], file_name[25];
    
        printf("This program ask a user to enter a name of file to create, then add random float data to the file, and finally print the sum of all the float data in the file \n\n");
    
        strcpy(file_path,"/Users/Big Name/Documents/School_C_Lab/");
        printf("Name of file: ");
        scanf("%s", &file_name);
        strcat(file_name,".txt");
        strcat(file_path,file_name);
    
        file = fopen(file_path, "w");
    
        //Write random double data to the file, each in new line
        for(int i = 0; i < 10; i++){
            fprintf(file,"%.2f\n",randnum(100, 1000)/3.9);
        }
    
        fclose(file);
    
        // Task 2
        FILE* filePointer;
        int bufferLength = 255;
        char buffer[bufferLength];
        double eachItem;
        double total = 0.0;
    
        filePointer = fopen("/Users/Big Name/Documents/School_C_Lab/st.csv", "r");
    
        printf("Sum of all doubles stored in %s = ", file_name);
        while(fgets(buffer, bufferLength, filePointer)) {
            sscanf(buffer, "%lf", &eachItem);
            total = total +eachItem;
        }
        printf("%.2f ", total);
        fclose(filePointer);
    
        return 0;
    }
    
