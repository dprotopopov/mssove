#include "Header.hpp"
/***********************************************
������ ����

field[WIDTH][HEIGHT] - ������� ��������� ����
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