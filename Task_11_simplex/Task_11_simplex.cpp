#include "Header.hpp"
using namespace std;

// 11. ������ n ������� ���������, ���������� m ��������� ����������� �������. 
// ��������� ����� aij ���������� (����) j-�� ������������ �������� � i-�� ��������, 
// ����� bj � �������� ����������� ��������� � j-�� ����������� ��������, 
// ����� ci � ��������� ������� i-�� ��������. 
// ��������� �������� ������ ������� ����������� ���������, 
// ��������������� ����������� �� ���� ����������� ���������.

int main()
{
	int m; // ���������� ����������
	int n; // ���������� ����������
	double **a;
	double *b;
	double *c;
	double *x;
	int demo; // ����� ���������

	setlocale(LC_ALL, "Russian");

	cout << "\t���������� ����� �������� �������� ������� f(x)=cx" << endl;
	cout << "\t��� ����������� ���� ax>=b � ����������� b>=0,x>=0" << endl;

	cout << "\t������� ���������� ����������:" << endl; cin >> m;
	cout << "\t������� ���������� ����������:" << endl; cin >> n;

	a = new double*[m];
	for(int i = 0; i < m; i++)
		a[i] = new double[n];

	b = new double[m];
	c = new double[n];

	cout << "\t������� ������� a["<<m<<","<<n<<"]:" << endl;
	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++) 
			cin >> a[i][j];
		
	cout << "\t������� ������ b["<<m<<"]:" << endl;
	for(int i = 0; i < m; i++)
		cin >> b[i];

	cout << "\t������� ������ c["<<n<<"]:" << endl;
	for(int j = 0; j < n; j++)
		cin >> c[j];

	cout << "\t���������������� ����� �������� (0 - ����� �������, 1 - ������������ �����������������):" << endl; cin >> demo;

	clock_t t = clock();
	if((x = ration(a, b, c, m, n, demo)) == NULL)
	{
		cout << "������� �� �������." << endl;
		getchar();
		getchar();
		return -1;
	}
	t = clock()-t;

	double seconds = ((double)t)/CLOCKS_PER_SEC;
	cout << "\t����� ����������: " << seconds << "sec" << endl;

	cout << "\t�������: " << endl;
	for(int j = 0; j < n; j++) cout << x[j] << '\t'; cout << endl;

	double f=0; for(int j = 0; j < n; j++) f+=c[j]*x[j];
	cout << "\t��������: " << endl;
	cout << f << endl;

	for(int i = 0; i < m; i++) delete a[i];
	delete a;
	delete b;
	delete c;
	delete x;

	getchar();
	getchar();

	return 0;
}

