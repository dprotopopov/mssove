#include "Header.hpp"
/***********************************************************************
����� ������������� � ������������ ��������

**data - �������
height - ������ ������� (���-�� �����)
width - ������ ������� (���-�� ��������)
&min - �����������  �������
&max - ������������ �������
***********************************************************************/



void findMinMax(double **data, int height, int width, double &min, double &max){

	min = max = data[0][0];

	double *temp = new double[height+1]; //+1 ��� �������� �������

	//����� ������������� �������� �� �������
	for(int str = 0; str < height; str++) {
		temp[str]=data[str][0];
		for(int col = 0; col < width; col++)
			if(temp[str] < data[str][col])
				temp[str] = data[str][col];
	}

	//����� ������������� �������� ����� ������������ ��������� �����
	//�������������� ����������
	for(int str = 0; str < height; str++) {
		if(max < temp[str])
			max = temp[str];
	}

	//����� ������������ �������� �� ��������
	for(int str = 0; str < height; str++) {
		temp[str]=data[str][0];
		for(int col = 0; col < width; col++)
			if(temp[str] > data[str][col])
				temp[str] = data[str][col];
	}

	//����� ������������ �������� ����� ����������� ��������� �����
	//�������������� ����������
	for(int str = 0; str < height; str++) {
		if(min > temp[str])
			min = temp[str];
	}

	delete temp;
}