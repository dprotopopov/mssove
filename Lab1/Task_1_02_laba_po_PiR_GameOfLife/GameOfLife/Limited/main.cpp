#include "Header.hpp"

const int max_iterations = 10;

int main()
{
	bool field[WIDTH][HEIGHT];
	
	FILE *f;

	if((f = fopen("in.txt", "r")) == NULL)
		return -1;

	for(int h = 0; h < HEIGHT; h++)
	{
		for(int w = 0; w < WIDTH; w++)
		{
			char c = getc(f);
			field[w][h] = (c == '1' ? true : false);
		}
		getc(f);
	}


	int i;
	for(i = 0; i < max_iterations; i++)
	{
		system("cls");
		printField(field);
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
	
	return 0;
}
