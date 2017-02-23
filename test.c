#include <stdio.h>
#include <stdlib.h>


int main()
{
	int dice;

	for(int i = 0; i <= 20; i++)
	{
		dice = ( rand() % 6) + 1;
		printf("%d \n", dice);
	}

	
}