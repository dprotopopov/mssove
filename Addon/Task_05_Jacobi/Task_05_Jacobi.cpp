#include "Header.hpp"
using namespace std;

// 5. ������, ����������� ������� ����� � ��������� ������������� ���������� ��������� 
// (������� � ��������� ���� ������������� ����� 0, 
// ����������� �������������� �� ������ �������, 
// ������� ����������� �������� ��������� �������). 

int main(){

	int n; // ���������� ���������
	int *m; // ���������� ����� �� ������� �� ���������
	double value; // �������� �������� �����������
	int demo; // ����� ���������

	setlocale(LC_ALL, "Russian");

	cout << "\t������, ����������� ������� ����� � ��������� ������������� ���������� ���������" << endl;
	cout << "\t������ Lite" << endl;

	cout << "\t������� ���������� ���������:" << endl; cin >> n;

	m = new int[n];

	cout << "\t������� ���������� ����� �� ������� �� ��������� m["<<n<<"]:" << endl;
	cout << "\t��������!!! ���������� ����� == ������ ����� + 1" << endl;
	for(int i = 0; i < n; i++)
		cin >> m[i];

	cout << "\t������� �������� �������� �����������:" << endl; cin >> value;

	cout << "\t���������������� ����� �������� (0 - ����� �������, 1 - ������������ �����������������):" << endl; cin >> demo;

	clock_t t = clock();
	if(jacobi_field(n,m,value, demo)!=0) cout << "\t������ ������������� ������" << endl;
	t = clock()-t;

	double seconds = ((double)t)/CLOCKS_PER_SEC;
	cout << "\t����� ����������: " << seconds << "sec" << endl;

	delete m;

	getchar();
	getchar();

	return 0;
}

