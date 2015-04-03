#include "Header.hpp"
using namespace std;

// 12. ������ ��������� ��������. 
// ��� ���������� ������ ����� �����. 
// ������� � ��� ������������ ��������� ��������� �������, 
// ������� ������� (�������� ��������) � ����� ���������� ��������.  
// ����� ��� ������� � �������� �������. 
// ������ ������� ��������� � ��������� ������.

int main()
{
	int n; // ���������� ���������
	int *m; // ���������� ����� �� ������� �� ���������
	int *matrix; 
	int demo; // ����� ���������

	setlocale(LC_ALL, "Russian");

	cout << "\t������ ��������� ��������" << endl;

	cout << "\t������� ���������� ���������:" << endl; cin >> n;

	m = new int[n];

	cout << "\t������� ���������� ����� �� ������� �� ��������� m["<<n<<"]:" << endl;
	for(int i = 0; i < n; i++)
		cin >> m[i];

	int total = 1; for(int i = 0; i < n; i++) total*=m[i];
	matrix = new int[total];

	cout << "\t������� ������� a["<<total<<"]:" << endl;
	for(int i = 0; i < total; i++)
			cin >> matrix[i];
		
	cout << "\t���������������� ����� �������� (0 - ����� �������, 1 - ������������ �����������������):" << endl; cin >> demo;

	clock_t t = clock();
	if(area(matrix, m, n, demo)!=0) cout << "\t������ ������������� ������" << endl;
	t = clock()-t;

	double seconds = ((double)t)/CLOCKS_PER_SEC;
	cout << "\t����� ����������: " << seconds << "sec" << endl;

	delete m;
	delete matrix;

	getchar();
	getchar();

	return 0;
}

