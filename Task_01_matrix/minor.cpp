#include "Header.hpp"
/********************************************************
Вычисление минора для квадратной матрицы

**data - матрица
size - сторона матрицы
strin - строка, где располагается минор
colon - столбец, где располагается минор
*********************************************************/
double minor(double **data, int size, int strin, int colon){
	double resultMinor;

	double **result = new double*[size-1];
	for(int i = 0; i < size-1; i++)
		result[i] = new double[size-1];

	//Создание новой матрицы из старой, выкидыванием столбца colon и строки strin
	for(int col = 0; col < size; col++){
		for(int str = 0; str < size; str++){
			if(col != colon && str != strin)
				result[str-(str>strin)][col-(col>colon)] = data[str][col];
			}
		}
	resultMinor = det(size-1, result);//Вычисляем минор

	for(int i = 0; i < size-1; i++)
		delete []result[i];
	delete []result;

return resultMinor;
}