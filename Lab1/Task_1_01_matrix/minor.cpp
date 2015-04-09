#include "Header.hpp"
/********************************************************
¬ычисление минора дл€ квадратной матрицы

**data - матрица
size - сторона матрицы
strin - строка, где располагаетс€ минор
colon - столбец, где располагаетс€ минор
*********************************************************/
double minor(double **data, int size, int strin, int colon){
	double resultMinor;

	double **result = new double*[size-1];
	for(int i = 0; i < size-1; i++)
		result[i] = new double[size-1];

	for(int col = 0; col < size; col++){
		for(int str = 0; str < size; str++){
			if(col != colon && str != strin)
				result[str-(str>strin)][col-(col>colon)] = data[str][col];
			}
		}
	resultMinor = det(size-1, result);//¬ычисл€ем минор

	for(int i = 0; i < size-1; i++)
		delete []result[i];
	delete []result;

return resultMinor;
}