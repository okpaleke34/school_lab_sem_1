#include <stdio.h>
    #include <stdlib.h>
    
    int main()
    {
        int number_of_integers, count,sum;
        int* storage;
        printf("This program Read and store n integers from the user. It will first ask for the n integer \
         \nfrom the user then allocate dynamic memoery for the array using malloc, then compute and print the sum of them \n\n");
    
    
        printf("Enter the number of integer: ");
        scanf_s("%d", &number_of_integers);
        count = 0;
        //allocate dynamic memory size to the storage
        storage = (int*)malloc(number_of_integers * sizeof(int));
        // use a loop to get the input of n integers from the user
        while (count != number_of_integers) {
            printf("Enter integer %d: ",count+1);
            scanf_s("%d", &storage[count]);
            count++;
        }
        //set the sum to 0
        sum = 0;
        printf("The sum of the elements(");
        for (int i = 0; i < number_of_integers; i++) {
            sum = sum + storage[i];
            if (i == number_of_integers - 1) {
    
                printf("%d", storage[i]);
            }
            else {
    
                printf("%d + ", storage[i]);
            }
        }
    
        printf(") in the array is: %d\n", sum);
        return 0;
    }
    
