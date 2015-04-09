#include "Header.hpp"
using namespace std;

// 12. Задача выделения областей. 
// Дан квадратный массив целых чисел. 
// Область – это максимальное множество элементов массива, 
// которые связаны (являются соседями) и имеют одинаковые значения.  
// Найти все области в исходном массиве. 
// Каждую область поместить в отдельный массив.

int main()
{
	int n; // количество измерений
	int *m; // количество точек по каждому из измерений
	int *matrix; 
	int demo; // режим программы

	setlocale(LC_ALL, "Russian");

	cout << "\tЗадача выделения областей" << endl;

	cout << "\tВведите количество измерений:" << endl; cin >> n;

	m = new int[n];

	cout << "\tВведите количество точек по каждому из измерений m["<<n<<"]:" << endl;
	for(int i = 0; i < n; i++)
		cin >> m[i];

	int total = 1; for(int i = 0; i < n; i++) total*=m[i];
	matrix = new int[total];

	cout << "\tВведите матрицу a["<<total<<"]:" << endl;
	for(int i = 0; i < total; i++)
			cin >> matrix[i];
		
	cout << "\tДемонстрационный режим програмы (0 - замер времени, 1 - демонстрация работоспособности):" << endl; cin >> demo;

	clock_t t = clock();
	if(area(matrix, m, n, demo)!=0) cout << "\tОшибка аллокирования памяти" << endl;
	t = clock()-t;

	double seconds = ((double)t)/CLOCKS_PER_SEC;
	cout << "\tВремя выполнения: " << seconds << "sec" << endl;

	delete m;
	delete matrix;

	getchar();
	getchar();

	return 0;
}

