#include "Header.hpp"
using namespace std;

// 13. Вычислить интеграл с заданной точностью любым итерационным численным методом (указать, каким именно). 
// Вычисление производится методом последовательных приближений. 
// Входные данные: числа a и b, функция f(x) задается в тексте программы, точность е.

double e=1e-7; // Точность
double f(double x) // Функция
{
	return sin(x);
}

int main()
{
	double a,b;
	double s;
	int demo; // режим программы

	setlocale(LC_ALL, "Russian");

	cout << "\tЗадача вычислить интеграл итерационным численным методом" << endl;

	cout << "\tВведите диапазон интегрирования:" << endl; cin >> a >> b;
		
	cout << "\tДемонстрационный режим програмы (0 - замер времени, 1 - демонстрация работоспособности):" << endl; cin >> demo;

	clock_t t = clock();
	s=integral(f, a, b, e, demo);
	t = clock()-t;

	cout << "\tЗначение интеграла:" << s << endl;

	double seconds = ((double)t)/CLOCKS_PER_SEC;
	cout << "\tВремя выполнения: " << seconds << "sec" << endl;

	getchar();
	getchar();

	return 0;
}

