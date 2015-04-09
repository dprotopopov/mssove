#include "Header.hpp"
using namespace std;

// 13. ��������� �������� � �������� ��������� ����� ������������ ��������� ������� (�������, ����� ������). 
// ���������� ������������ ������� ���������������� �����������. 
// ������� ������: ����� a � b, ������� f(x) �������� � ������ ���������, �������� �.

double e=1e-7; // ��������
double f(double x) // �������
{
	return sin(x);
}

int main()
{
	double a,b;
	double s;
	int demo; // ����� ���������

	setlocale(LC_ALL, "Russian");

	cout << "\t������ ��������� �������� ������������ ��������� �������" << endl;

	cout << "\t������� �������� ��������������:" << endl; cin >> a >> b;
		
	cout << "\t���������������� ����� �������� (0 - ����� �������, 1 - ������������ �����������������):" << endl; cin >> demo;

	clock_t t = clock();
	s=integral(f, a, b, e, demo);
	t = clock()-t;

	cout << "\t�������� ���������:" << s << endl;

	double seconds = ((double)t)/CLOCKS_PER_SEC;
	cout << "\t����� ����������: " << seconds << "sec" << endl;

	getchar();
	getchar();

	return 0;
}

