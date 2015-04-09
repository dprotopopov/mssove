#include "Header.hpp"
/*****************************************************************
¬ычисление обратной матрицы (только дл€ квадратных)

**data - матрица
size - сторона матрицы

‘ункци€ возвращает NULL, если обратной матрицы не существует.
*****************************************************************/
double **inverse(double **data, int size){
	double **additionMatrix;//ћатрица алгебраических дополнений
	double detData;


	if((detData = det(size, data)) == 0)//вычисл€ем детерминант, если он равен нулю, то обратной матрицы не существует
		return NULL;


	additionMatrix = new double*[size];
	for(int str = 0; str < size; str++)
		additionMatrix[str] = new double[size];
	
	//ќтдельный случай дл€ матрицы 1х1
	if(size == 1)
	{
		additionMatrix[0][0] = 1/data[0][0];
		return additionMatrix;
	}

	for(int str = 0; str < size; str++)
		for(int col = 0; col < size; col++)
			if(((str+col) % 2) == 0)
				additionMatrix[str][col] =  minor(data, size, str, col);
			else
				additionMatrix[str][col] = -minor(data, size, str, col);

	transposeSQR(additionMatrix, size);//транспонируем матрицу


	for(int str = 0; str < size; str++)//делим элементы на детерминант
		for(int col = 0; col < size; col++)
			additionMatrix[str][col] /= detData;


	return additionMatrix;
}
