#include "Header.hpp"
/***************************************************************
���������� ����
field[WIDTH][HEIGHT] - ������� ����.

���������� true, ���� ���� �������� ��� ���������, ����� false
***************************************************************/
bool newField(cell field[WIDTH][HEIGHT])
{
	int countNeighbors = 0;			//���������� ����� �������
	bool notStatState = false;		//������������ ��������
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

			//�������� �� ���������� ������������� ��������
			if(field[w][h].age >= MAX_AGE)
				newField[w][h].currentState = false;


			//��������� �������� ��� ������
			if((newField[w][h].currentState == true) && (field[w][h].currentState == false))
				field[w][h].age = 0;

			//���������� �������� ����� ������
			if((newField[w][h].currentState == true) && (field[w][h].currentState == true))
				++field[w][h].age;

			//�������� �� ���������� ������������� ��������
			if(field[w][h].age >= MAX_AGE)
				newField[w][h].currentState = false;

		}


		for(int h = 0; h < HEIGHT; h++)
			for(int w = 0; w < WIDTH; w++)
				field[w][h].currentState = newField[w][h].currentState;
		return notStatState;
}