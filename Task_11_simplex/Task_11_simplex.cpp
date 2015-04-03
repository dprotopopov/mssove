#include "Header.hpp"
using namespace std;

// 11. «аданы n пищевых продуктов, содержащих m различных питательных веществ. 
// ќбозначим через aij содержание (долю) j-го питательного вещества в i-ом продукте, 
// через bj Ч суточную потребность организма в j-ом питательном веществе, 
// через ci Ч стоимость единицы i-го продукта. 
// —оставить суточный рацион питани€ минимальной стоимости, 
// удовлетвор€ющий потребность во всех питательных веществах.

int main()
{
	int m; // количество неравенств
	int n; // количество переменных
	double **a;
	double *b;
	double *c;
	double *x;
	int demo; // режим программы

	setlocale(LC_ALL, "Russian");

	cout << "\t¬ычисление точки минимума линейной функции f(x)=cx" << endl;
	cout << "\tƒл€ неравенства вида ax>=b и ограничени€ b>=0,x>=0" << endl;

	cout << "\t¬ведите количество неравенств:" << endl; cin >> m;
	cout << "\t¬ведите количество переменных:" << endl; cin >> n;

	a = new double*[m];
	for(int i = 0; i < m; i++)
		a[i] = new double[n];

	b = new double[m];
	c = new double[n];

	cout << "\t¬ведите матрицу a["<<m<<","<<n<<"]:" << endl;
	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++) 
			cin >> a[i][j];
		
	cout << "\t¬ведите вектор b["<<m<<"]:" << endl;
	for(int i = 0; i < m; i++)
		cin >> b[i];

	cout << "\t¬ведите вектор c["<<n<<"]:" << endl;
	for(int j = 0; j < n; j++)
		cin >> c[j];

	cout << "\tƒемонстрационный режим програмы (0 - замер времени, 1 - демонстраци€ работоспособности):" << endl; cin >> demo;

	clock_t t = clock();
	if((x = ration(a, b, c, m, n, demo)) == NULL)
	{
		cout << "–ешение не найдено." << endl;
		getchar();
		getchar();
		return -1;
	}
	t = clock()-t;

	double seconds = ((double)t)/CLOCKS_PER_SEC;
	cout << "\t¬рем€ выполнени€: " << seconds << "sec" << endl;

	cout << "\t–ешение: " << endl;
	for(int j = 0; j < n; j++) cout << x[j] << '\t'; cout << endl;

	double f=0; for(int j = 0; j < n; j++) f+=c[j]*x[j];
	cout << "\t«начение: " << endl;
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

