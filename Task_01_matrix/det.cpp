#include "Header.hpp"
/*******************************************
������������ ���������� �������

size - ������� �������
**data - �������

*******************************************/
double det(int size, double **data){
	int str, col, currCol;
	double result = 0;//��������� ���������� (�����������)
	

	if(size == 1)
		return data[0][0];

	double **newData = new double*[size-1];

	for(str = 0; str < size-1; str++)
		newData[str] = new double[size-1];

	//�������� ����� ������� �� ������, ������������ ������� col � ������ str
	for(col = 0; col < size; col++){
		for(currCol = 0; currCol < size; currCol++){
			if(currCol != col)
				for(str = 1; str < size; str++){
						newData[str-1][currCol-(currCol>col)] = data[str][currCol];
					}
				}
		if(col%2)
			result -= data[0][col]*det(size-1, newData);
		else
			result += data[0][col]*det(size-1, newData);
	}

	for(int i = 0; i < size-1; i++)
		delete []newData[i];
	delete []newData;
	return result;
}
