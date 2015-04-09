#include "Header.hpp"
/***************************************************************
Обновление поля
field[WIDTH][HEIGHT][DEPTH] - текущее поле.

Возвращает true, если поле изменило своё состояние, иначе false
***************************************************************/
bool newField(bool field[WIDTH][HEIGHT][DEPTH])
{
	int countNeighbors = 0;					//Количество живых соседей
	bool notStatState = false;				//Возвращаемое значение
	bool newField[WIDTH][HEIGHT][DEPTH];
	

	for(int h = 0; h < HEIGHT; h++)
		for(int w = 0; w < WIDTH; w++)
			for(int d = 0; d < DEPTH; d++)
			{
				countNeighbors = 0;
				if(w > 0)
					countNeighbors += field[w-1][h][d];
				if(w < WIDTH-1)
					countNeighbors += field[w+1][h][d];
				if(h > 0)
					countNeighbors += field[w][h-1][d];
				if(h < HEIGHT-1)
					countNeighbors += field[w][h+1][d];
				if(d > 0)
					countNeighbors += field[w][h][d-1];
				if(d < DEPTH-1)
					countNeighbors += field[w][h][d+1];
				newField[w][h][d] = newState(field[w][h][d], countNeighbors);
				if(newField[w][h][d] != field[w][h][d])
					notStatState = true;
			}


		for(int h = 0; h < HEIGHT; h++)
			for(int w = 0; w < WIDTH; w++)
				for(int d = 0; d < DEPTH; d++)
					field[w][h][d] = newField[w][h][d];
		return notStatState;
}