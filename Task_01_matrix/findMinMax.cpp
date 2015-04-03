#include "Header.hpp"
/***********************************************************************
����� ������������� �������� �� �������, ������������ �� ��������

**data - �������
height - ������ ������� (���-�� �����)
weight - ������ ������� (���-�� ��������)
&min - �����������  �������
&max - ������������ �������
***********************************************************************/



void findMinMax(double **data, int height, int weight, double &min, double &max){

	min = max = data[0][0];

	//����� ������������� �������� �� �������
	for(int str = 0; str < height; str++)
		for(int col = 0; col < weight; col++)
			if(max < data[str][col])
				max = data[str][col];
	

	//����� ������������ �������� �� ��������
	for(int col = 0; col < weight; col++)
		for(int str = 0; str < height; str++)
			if(min > data[str][col])
				min = data[str][col];
}