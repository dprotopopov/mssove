#include "Header.hpp"
/*********************************************
Транспонирование квадратной матрицы

**data - матрица
size - сторона матрицы
*********************************************/
void transposeSQR(double **data, int size){
	double temp;

	for(int str = 0; str < size; str++)
		for(int col = str+1; col < size; col++)
			data[str][col] = (temp = data[col][str], data[col][str] = data[str][col], temp);

}