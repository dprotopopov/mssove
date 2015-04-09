#include "Header.hpp"
/***********************************************
������ ����

field[WIDTH][HEIGHT] - ������� ��������� ����
***********************************************/
void printField(const cell field[WIDTH][HEIGHT])
{
	for(int h = 0; h < HEIGHT; h++)
	{
		for(int w = 0; w < WIDTH; w++)
			putchar(field[w][h].currentState ? field[w][h].age+'0'/*LIFE*/ : DIE);
		putchar('\n');
	}
}