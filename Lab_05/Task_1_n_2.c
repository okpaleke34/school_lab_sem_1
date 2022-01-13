#include <stdio.h>
#define N 5

//This is the  task 2 as function in task 1
int findMax(int data[])
{
    // set max to 0
  int max = 0;
  for (int i = 0; i < N; i++)
    {
        //it iterates the data and check if the value is bigger than the already set max and overide it
        if(data[i] > max){
            max = data[i];
        }
    }
  return max;
}


int main()
{


  int i;
  int userInput[N];
  for (i = 0; i < N; i++)
    {
      printf("Integer - %d: ", i + 1);
      scanf("%d",&userInput[i]);
    }

  printf("The values store into array are : \n");
  for (i = 0; i < N; i++)
    {
      printf("%d ", userInput[i]);
    }

  printf ("\n\nThe values store into array in reverse  are :\n");
  for (i = N - 1; i >= 0; i--)
    {
      printf("%d ", userInput[i]);
    }

    
    printf("\n The maximum integer is:  %d \n", findMax(userInput));

  return 0;
}
