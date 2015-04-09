#include "Header.hpp"
/*****************************************************************
���������� �������� ������� (������ ��� ����������)

**data - �������
size - ������� �������

������� ���������� NULL, ���� �������� ������� �� ����������.
*****************************************************************/
double **inverse(double **data, int size){
	double **additionMatrix;//������� �������������� ����������
	double detData;


	if((detData = det(size, data)) == 0)//��������� �����������, ���� �� ����� ����, �� �������� ������� �� ����������
		return NULL;


	additionMatrix = new double*[size];
	for(int str = 0; str < size; str++)
		additionMatrix[str] = new double[size];
	
	//��������� ������ ��� ������� 1�1
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

	transposeSQR(additionMatrix, size);//������������� �������


	for(int str = 0; str < size; str++)//����� �������� �� �����������
		for(int col = 0; col < size; col++)
			additionMatrix[str][col] /= detData;


	return additionMatrix;
}
