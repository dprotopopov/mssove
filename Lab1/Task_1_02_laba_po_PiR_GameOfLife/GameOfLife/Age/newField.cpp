#include "Header.hpp"
/***************************************************************
Обновление поля
field[WIDTH][HEIGHT] - текущее поле.

Возвращает true, если поле изменило своё состояние, иначе false
***************************************************************/
bool newField(cell field[WIDTH][HEIGHT])
{
	int countNeighbors = 0;			//Количество живых соседей
	bool notStatState = false;		//Возвращаемое значение
	cell newField[WIDTH][HEIGHT];
	

	for(int h = 0; h < HEIGHT; h++)
		for(int w = 0; w < WIDTH; w++)
		{
			countNeighbors = 0;
			countNeighbors += field[w == 0 ? WIDTH-1 : (w-1)]	[h]							 .currentState;
			countNeighbors += field[(w+1)%WIDTH]				[h]							 .currentState;
			countNeighbors += field[w]							[h == 0 ? HEIGHT - 1 : (h-1)].currentState;
			countNeighbors += field[w]							[(h+1)%HEIGHT]				 .currentState;
			newField[w][h].currentState = newState(field[w][h].currentState, countNeighbors);
			if(newField[w][h].currentState != field[w][h].currentState)
				notStatState = true;

			//Проверка на достижение максимального возраста
			if(field[w][h].age >= MAX_AGE)
				newField[w][h].currentState = false;


			//Обнуление возраста при смерти
			if((newField[w][h].currentState == true) && (field[w][h].currentState == false))
				field[w][h].age = 0;

			//Увеличение возраста живой клетки
			if((newField[w][h].currentState == true) && (field[w][h].currentState == true))
				++field[w][h].age;

			//Проверка на достижение максимального возраста
			if(field[w][h].age >= MAX_AGE)
				newField[w][h].currentState = false;

		}


		for(int h = 0; h < HEIGHT; h++)
			for(int w = 0; w < WIDTH; w++)
				field[w][h].currentState = newField[w][h].currentState;
		return notStatState;
}