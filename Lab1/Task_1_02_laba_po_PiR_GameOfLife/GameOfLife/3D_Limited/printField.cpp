#include "Header.hpp"
/************************************************************
Печать поля

field[WIDTH][HEIGHT][DEPTH] - текущее состояние поля
************************************************************/
void printField(const bool field[WIDTH][HEIGHT][DEPTH])
{
	for(int d = 0; d < DEPTH; d++)
	{
		cout << "Layer " << d+1 << endl << endl;
		for(int h = 0; h < HEIGHT; h++)
		{
			for(int w = 0; w < WIDTH; w++)
				putchar(field[w][h][d] ? LIFE : DIE);
			cout << endl;
		}
		cout << endl;
	}
}