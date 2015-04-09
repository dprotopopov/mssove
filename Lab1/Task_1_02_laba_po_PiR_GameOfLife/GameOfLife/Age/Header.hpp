#include <iostream>
#include <windows.h>

using namespace std;

//Состояние клетки (для печати)
#define LIFE	219
#define DIE		'.'

//Параметры поля
#define WIDTH 	6
#define HEIGHT  6

//Задержка перед обновлением поля
#define DELAY	1000

//Максимальный возраст живой клетки
#define MAX_AGE 5

//Состояние клетки
typedef struct cell
{
	bool currentState;
	int age;
}cell;

//Новое состояние клетки
bool newState(const bool oldState, const int neighborCnt);

//Обновление поля
bool newField(cell field[WIDTH][HEIGHT]);

//Печать поля
void printField(const cell field[WIDTH][HEIGHT]);