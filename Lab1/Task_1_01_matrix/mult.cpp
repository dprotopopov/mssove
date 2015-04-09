#include "Header.hpp"
/*****************************************************************************
Произведение матриц

**data1 - первый множитель
**data2 - второй множитель
size1 - кол-во строк в первой матрице
size2 - колво столбцов в первой матрице и кол-во строк во второй
size3 - кол-во столбцов во второй матрице
*****************************************************************************/
double **mult(double **data1, double **data2, const int size1, const int size2, const int size3){
	double ** result;

	result = new double *[size1];//результат произведения

	for(int i = 0; i < size1; i++)
		result[i] = new double[size3];


	for(int str = 0; str < size1; str++)//строки первой матрицы
	{
		for(int col = 0; col < size3; col++)//столбцы второй матрицы
		{
			result[str][col] = 0;
			for(int i = 0; i < size2; i++)
				result[str][col] += data1[str][i]*data2[i][col];
		}
	}
	return result;
}

			
