#include "Header.hpp"
using namespace std;

int main(){

	setlocale(LC_ALL, "Russian");

	cout << "\tМеню:" << endl;
	cout << "\t0 Минимальный и максимальный элементы матрицы" << endl;
	cout << "\t1 Умножение матриц" << endl;
	cout << "\t2 Определитель квадратной матрицы" << endl;
	cout << "\t3 Обратная матрица к квадратной матрице" << endl;
	cout << "\t4 Алгоритм быстрой сортировки" << endl;
	cout << "\t5 Алгоритм битонической сортировки" << endl;

	int menu; cin >> menu;

	switch(menu){
	case 0:
		{
			// Минимальный и максимальный элементы матрицы
			int size1;
			int size2;
			cout << "\tРазмеры матрицы [2]:" << endl; cin >> size1; cin >> size2;
			double **a = new double*[size1];

			for(int i = 0; i < size1; i++)
				a[i] = new double[size2];

			cout << "\tМатрица A["<<size1<<","<<size2<<"]:" << endl;
			for(int i = 0; i < size1; i++)
				for(int j = 0; j < size2; j++)
					cin >> a[i][j];


			clock_t t = clock();
			double min, max;
			findMinMax(a, size1, size2, min, max);
			t = clock()-t;

			double seconds = ((double)t)/CLOCKS_PER_SEC;
			cout << "\tВремя выполнения: " << seconds << "sec" << endl;

			cout << "Минимальный элемент матрицы: " << min << endl
				<< "Максимальный элемент матрицы: " << max << endl;

			for(int i = 0; i < size1; i++) delete a[i];

			delete a;
		}
		break;
	case 1:
		{
			// Умножение матриц
			int size1;
			int size2;
			int size3;
			cout << "\tРазмеры матриц [3]:" << endl; cin >> size1 >> size2 >> size3;
			double **a = new double*[size1];
			double **b = new double*[size2];

			for(int i = 0; i < size1; i++)
				a[i] = new double[size2];
			for(int i = 0; i < size2; i++)
				b[i] = new double[size3];

			cout << "\tМатрица A["<<size1<<","<<size2<<"]:" << endl;
			for(int i = 0; i < size1; i++)
				for(int j = 0; j < size2; j++)
					cin >> a[i][j];

			cout << "\tМатрица B["<<size2<<","<<size3<<"]:" << endl;
			for(int i = 0; i < size2; i++)
				for(int j = 0; j < size3; j++)
					cin >> b[i][j];

			clock_t t = clock();
			double **c = mult(a, b, size1, size2, size3);
			t = clock()-t;

			double seconds = ((double)t)/CLOCKS_PER_SEC;
			cout << "\tВремя выполнения: " << seconds << "sec" << endl;

			cout << "\tРезультат произведения" << endl;
			for(int i = 0; i < size1; i++)
			{
				for(int j = 0; j < size3; j++)
					cout << c[i][j]  << '\t';
				cout << endl;
			}

			for(int i = 0; i < size1; i++) delete a[i];
			for(int i = 0; i < size2; i++) delete b[i];
			for(int i = 0; i < size1; i++) delete c[i];

			delete a;
			delete b;
			delete c;
		}
		break;
	case 2:
		{
			// Определитель квадратной матрицы
			int size;
			cout << "\tРазмеры матрицы:" << endl; cin >> size;
			double **a = new double*[size];
			for(int i = 0; i < size; i++)
				a[i] = new double[size];

			cout << "\tМатрица A["<<size<<","<<size<<"]:" << endl;
			for(int i = 0; i < size; i++)
				for(int j = 0; j < size; j++)
					cin >> a[i][j];

			clock_t t = clock();
			cout << "\tОпределитель матрицы равен "  << det(size, a) << endl;
			t = clock()-t;

			double seconds = ((double)t)/CLOCKS_PER_SEC;
			cout << "\tВремя выполнения: " << seconds << "sec" << endl;


			for(int i = 0; i < size; i++) delete a[i];

			delete a;
		}
		break;
	case 3:
		{
			// Обратная матрица к квадратной матрице
			int size;
			cout << "\tРазмеры матрицы:" << endl; cin >> size;
			double **a = new double*[size];
			for(int i = 0; i < size; i++)
				a[i] = new double[size];

			cout << "\tМатрица A["<<size<<","<<size<<"]:" << endl;
			for(int i = 0; i < size; i++)
				for(int j = 0; j < size; j++)
					cin >> a[i][j];

			clock_t t = clock();
			double **b = inverse(a, size);
			t = clock()-t;

			double seconds = ((double)t)/CLOCKS_PER_SEC;
			cout << "\tВремя выполнения: " << seconds << "sec" << endl;

			if(b == NULL)
			{
				cout << "Ошибка: определитель матрицы равен 0. Обратной матрицы не существует." << endl;
				getchar();
				getchar();
				return -1;
			}

			cout << "\tОбратная матрица: " << endl;
			for(int i = 0; i < size; i++)
			{
				for(int j = 0; j < size; j++)
					cout << b[i][j] << '\t';
				cout << endl;
			}

			for(int i = 0; i < size; i++) delete a[i];
			for(int i = 0; i < size; i++) delete b[i];

			delete a;
			delete b;
		}
		break;
	case 4:
		{
			// Алгоритм быстрой сортировки
			int size;
			cout << "\tРазмер массива:" << endl; cin >> size;
			double *a = new double[size];
			cout << "\tИсходный массив["<<size<<"]:" << endl;
			for(int i = 0; i < 10; i++)  cin >> a[i];

			clock_t t = clock();
			quickSort(a, 0, size-1);
			t = clock()-t;

			double seconds = ((double)t)/CLOCKS_PER_SEC;
			cout << "\tВремя выполнения: " << seconds << "sec" << endl;

			cout << "\tСортированный массив["<<size<<"]:" << endl;
			for(int i = 0; i < 10; i++) cout << a[i] << '\t'; cout << endl;
			delete a;
		}
		break;
	case 5:
		{
			// Алгоритм битонической сортировки
			int size;
			cout << "\tРазмер массива:" << endl; cin >> size;
			double *a = new double[size];
			cout << "\tмассив["<<size<<"]:" << endl;
			for(int i = 0; i < 10; i++)  cin >> a[i];

			clock_t t = clock();
			host_bitonic_sort(a, size, 1);
			t = clock()-t;

			double seconds = ((double)t)/CLOCKS_PER_SEC;
			cout << "\tВремя выполнения: " << seconds << "sec" << endl;

			cout << "\tСортированный массив["<<size<<"]:" << endl;
			for(int i = 0; i < 10; i++) cout << a[i] << '\t'; cout << endl;
			delete a;
		}
		break;
	}

	getchar();
	getchar();

	return 0;
}