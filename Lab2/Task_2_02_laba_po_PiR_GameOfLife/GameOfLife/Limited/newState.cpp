#include "Header.hpp"
/********************************************************************************************
Получение нового состояния клетки в зависимости от старого состояния и количества соседей.

oldState	- старое состояние клетки
neighborCnt - количество живых соседей
********************************************************************************************/

bool newState(const bool oldState, const int neighborCnt)
{
	if(oldState == true)
	{
		if(neighborCnt <  2)	return false;
		if(neighborCnt <  4)	return true;
		if(neighborCnt == 4)	return false;
	}
	if(oldState == false)
	{
		if(neighborCnt == 2)	return true;
	}

	return oldState;
}

