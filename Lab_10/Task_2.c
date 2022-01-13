
#include <stdio.h>
    #include <stdlib.h>
    
    int* copy_array(int* ptr, int num_of_elements) {
        int *new_array = (int*)malloc(sizeof(int) * num_of_elements);
        for (int i = 0; i < num_of_elements; i++) {
            *&new_array[i] = *&ptr[i];
        }
        return new_array;
    }
    int main()
    {
        int student_mark[4] = { 10, 3, 4, 6 };
        int sizeof_student_mark = sizeof(student_mark) / sizeof(int);
        //copy the student array using the copy_array function
        int * new_array = copy_array(&student_mark, sizeof_student_mark);
    
        printf("Pointer to the copied array copy: %p\n", new_array);
    
        printf("Loop through the copy array and make sure they are same.\n\n");
    
        for (int i = 0; i < sizeof_student_mark; i++) {
            printf("Array Data %d: %d \n",i, *&new_array[i]);
        }
    
    
        return 0;
    }
    
