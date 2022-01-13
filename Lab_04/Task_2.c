#include <math.h>
#include <stdlib.h>

int horizontal_lines(int x){

	for (int i = 1; i <= x*8.3; i++)
	{
		printf("-");
	}
	return 0;
}

int main()
{
	int x, y;
	x = 10;
	y = 15;
	for (int i = 1; i <= x; i++)
	{
		printf("\t%d", i);
	}
	printf("\n");
	horizontal_lines(x);

	for (int i = 1; i <= y; i++)
	{
		printf("\n");
		for (int j = 0; j <= x; j++)
		{
            if(j == 0){
                printf("%-3d | ", i * (j+1));
            }
            else{
                printf("%-3d \t", i * j);
            }
		}

	}
	printf("\n");
	horizontal_lines(x);

	return 0;
}
