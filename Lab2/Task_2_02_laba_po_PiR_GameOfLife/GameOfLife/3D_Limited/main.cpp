#include "Header.hpp"

const int max_iterations = 10;

int main()
{
	bool field[WIDTH][HEIGHT][DEPTH];
	
	FILE *f;

	if((f = fopen("in.txt", "r")) == NULL)
		return -1;

	for(int d = 0; d < DEPTH; d++)
	{
		for(int h = 0; h < HEIGHT; h++)
		{
			for(int w = 0; w < WIDTH; w++)
			{
				char c = getc(f);
				field[w][h][d] = (c == '1' ? true : false);
			}
			getc(f);
		}
		getc(f);
	}


	int i;
	for(i = 0; i < max_iterations; i++)
	{
		system("cls");
		printField(field);cout << endl;
		Sleep(DELAY);
		if(!newField(field))
			break;
		cout << endl <<  endl;
	}

	setlocale(LC_ALL, "Russian");
	if(i == max_iterations)
		cout << "ƒостигнуто максимальное количество итераций." << endl;
	else
		cout << "ѕоле пришло в стационарное состо€ние." << endl << endl << endl;
	getchar();
	return 0;
}

