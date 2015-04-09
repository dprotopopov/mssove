#include "Header.hpp"
/*****************************************************************************
������������ ������

**data1 - ������ ���������
**data2 - ������ ���������
size1 - ���-�� ����� � ������ �������
size2 - ����� �������� � ������ ������� � ���-�� ����� �� ������
size3 - ���-�� �������� �� ������ �������
*****************************************************************************/
double **mult(double **data1, double **data2, const int size1, const int size2, const int size3){
	double ** result;

	result = new double *[size1];//��������� ������������

	for(int i = 0; i < size1; i++)
		result[i] = new double[size3];


	for(int str = 0; str < size1; str++)//������ ������ �������
	{
		for(int col = 0; col < size3; col++)//������� ������ �������
		{
			result[str][col] = 0;
			for(int i = 0; i < size2; i++)
				result[str][col] += data1[str][i]*data2[i][col];
		}
	}
	return result;
}

			
