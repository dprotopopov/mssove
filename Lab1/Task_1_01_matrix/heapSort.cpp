#include "Header.hpp"
/***************************************
Пирамидальная сортировка

data - массив элементов
length - длина массива
***************************************/


void heapSort(double *data, int length)
{
	double swap;
	for(int j = length-1; j > 0; --j)
	{
		for(int i = j/2; i >= 0; i--)
		{
			if(data[i] < data[2*i+1] && 2*i+1 <= j)
				data[i] = (swap = data[2*i+1], data[2*i+1] = data[i], swap);
			if(data[i] < data[2*i+2] && 2*i+2 <= j)
				data[i] = (swap = data[2*i+2], data[2*i+2] = data[i], swap);
		}
		data[0] = (swap = data[j], data[j] = data[0], swap);	
	}
}