#include "Header.hpp"
/***************************************************************
Обновление поля
field[WIDTH][HEIGHT] - текущее поле.

Возвращает true, если поле изменило своё состояние, иначе false
***************************************************************/
bool newField(bool field[WIDTH][HEIGHT])
{
	int countNeighbors = 0;			//Количество живых соседей
	bool notStatState = false;		//Возвращаемое значение
	bool newField[WIDTH][HEIGHT];
	

	for(int h = 0; h < HEIGHT; h++)
		for(int w = 0; w < WIDTH; w++)
		{
			countNeighbors = 0;
			if(w > 0)
				countNeighbors += field[w-1][h];
			if(w < WIDTH-1)
				countNeighbors += field[w+1][h];
			if(h > 0)
				countNeighbors += field[w][h-1];
			if(h < HEIGHT-1)
				countNeighbors += field[w][h+1];
			newField[w][h] = newState(field[w][h], countNeighbors);
			if(newField[w][h] != field[w][h])
				notStatState = true;
		}


		for(int h = 0; h < HEIGHT; h++)
			for(int w = 0; w < WIDTH; w++)
				field[w][h] = newField[w][h];
		return notStatState;
}