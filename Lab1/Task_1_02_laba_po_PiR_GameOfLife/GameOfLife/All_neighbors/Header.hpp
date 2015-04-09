#include <iostream>
#include <windows.h>

using namespace std;

//Состояние клетки (для печати)
#define LIFE	219
#define DIE		'.'

//Параметры поля
#define WIDTH 	4
#define HEIGHT 	4

//Задержка перед обновлением поля
#define DELAY	1000

//Новое состояние клетки
bool newState(const bool oldState, const int neighborCnt);

//Обновление поля
bool newField(bool field[WIDTH][HEIGHT]);

//Печать поля
void printField(const bool field[WIDTH][HEIGHT]);
