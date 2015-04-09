#include "Header.hpp"
/*******************************************
Определитель квадратной матрицы

size - сторона матрицы
**data - матрица

*******************************************/
double det(int size, double **data){
	int str, col, currCol;
	double result = 0;//результат выполнения (детерминант)

		double *temp = new double[size+1]; //+1 для нулевого размера


	if(size == 1)
		return data[0][0];

	for(col = 0; col < size; col++){
		double **newData = new double*[size-1];

		for(str = 0; str < size-1; str++)
			newData[str] = new double[size-1];

		//Создание новой матрицы из старой, выкидыванием столбца col и строки str
		for(currCol = 0; currCol < size; currCol++){
			if(currCol != col)
				for(str = 1; str < size; str++){
						newData[str-1][currCol-(currCol>col)] = data[str][currCol];
					}
				}
		if(col%2)
			temp[col] =- data[0][col]*det(size-1, newData);
		else
			temp[col] = data[0][col]*det(size-1, newData);

		for(int i = 0; i < size-1; i++)
			delete []newData[i];

		delete []newData;
	}

	for(col = 0; col < size; col++) result+=temp[col];
	delete temp;

	return result;
}
