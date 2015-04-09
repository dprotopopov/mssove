#include "Header.hpp"
/*********************************************
���������������� ���������� �������

**data - �������
size - ������� �������
*********************************************/
void transposeSQR(double **data, int size){

	for(int str = 0; str < size; str++)
		for(int col = str+1; col < size; col++) {
			double temp;
			data[str][col] = (temp = data[col][str], data[col][str] = data[str][col], temp);
		}

}