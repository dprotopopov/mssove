#include "Header.hpp"
/***********************************************
Печать поля

field[WIDTH][HEIGHT] - текущее состояние поля
***********************************************/
void printField(const bool field[WIDTH][HEIGHT])
{
	for(int h = 0; h < HEIGHT; h++)
	{
		for(int w = 0; w < WIDTH; w++)
			putchar(field[w][h] ? LIFE : DIE);
		putchar('\n');
	}
}