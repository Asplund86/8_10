#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define COLS 4

_Bool magisk(int array[][COLS], int rows)
{
	if(rows != COLS)
		return 0;

	//Kontrollera radlängder och diagonalsummorna
	int diagonal1 = 0, diagonal2 = 0;

	for(int i = 0; i < rows; i++)
	{
		diagonal1 = diagonal1 + array[i][i];
		diagonal2 = diagonal2 + array[i][4-i-1];
	}
	if(diagonal1 != diagonal2)
		return 0;

	//Kontrollera radsummorna.
	for(int i = 0; i < rows; i++)
	{
		int sum_row = 0;
		for(int j = 0; j < COLS; j++)
			sum_row = sum_row + array[i][j];
		if(sum_row != diagonal1)
			return 0;
	}

	//Kontrollera kolumnsummorna.
	for(int i = 0; i < rows; i++)
	{
		int sum_col = 0;
		for(int j = 0; j < COLS; j++)
			sum_col = sum_col + array[j][i];
		if(sum_col != diagonal1)
			return 0;
	}

	return 1;

}


int main()
{
	int sum_kolumner = 0;
	int sum_kolumner_compare = 0;
	int magisk_array[COLS][COLS];

	// I while-loopen ger vi varje element ett random nummer 
	// tills magisk funktionen är true.

	while(1)
	{
		for(int i = 0; i < COLS; i++)
		{
			for(int j = 0; j < COLS; j++)
			{
				int random = ( rand() % 6) + 1;
				magisk_array[i][j] = random;
			}
		}
		if(magisk(magisk_array, COLS))
			break;

	}

	//Här skriver vi ut array.


	for(int i = 0; i < COLS; i++)
	{
		for(int j = 0; j <COLS; j++)
		{
			printf("%d\t", magisk_array[i][j]);
		}
		printf("\n");
	}
}