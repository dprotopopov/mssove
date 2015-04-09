#include "Header.hpp"
/****************************************************
Быстрая сортировка Хоара

*data - массив элементов
left -  номер первого		элемента сортируемого массива
right - номер последнего	элемента сортируемого массива

*****************************************************/
void quickSort(double *data, int left, int right)
{
	int left1 = left;
	int right1 = right;
	double p;
	double ref = data[(left+right)/2];
		
	do{
		while(data[left1] < ref)left1++;
		while(data[right1] > ref)right1--;
		if(left1<=right1){
			if(data[left1] > data[right1])
				data[left1]  = (p = data[right1], data[right1] = data[left1], p);
			left1++;
			right1--;
		}
	}while (left1 <= right1);

	if(left1 < right) 
		quickSort(data, left1, right);

	if(left < right1) 
		quickSort(data, left, right1);
}