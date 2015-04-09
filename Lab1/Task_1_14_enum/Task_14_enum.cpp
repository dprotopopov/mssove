#include "Header.hpp"
using namespace std;

// 14. ����������, �������� �� ��������� � 
// ������������ �������� A � B (A B), 
// ������������ �������� A � B (A B), 
// ��������� �������� � � B (A\B), 
// ��������� �������� � � � (�\�).

// �������� ��������� �������� �������������� ����������������

int main()
{
	int *a; // �������������� ��������� ��������� A
	int *b; // �������������� ��������� ��������� B
	int *c; // �������������� ��������� ��������� C

	int na; // ���������� ��������� ��������� A
	int nb; // ���������� ��������� ��������� B
	int nc; // ���������� ��������� ��������� C

	int demo; // ����� ���������

	setlocale(LC_ALL, "Russian");

	cout << "\t����������, �������� �� ��������� �" << endl;
	cout << "\t������������ �������� A � B" << endl;
	cout << "\t������������ �������� A � B" << endl;
	cout << "\t��������� �������� � � B" << endl;
	cout << "\t��������� �������� � � �" << endl;

	cout << "\t������� ���������� ��������� ��������� A:" << endl; cin >> na;
	a = new int[na+1]; // +1 ��� ������ ������� ���������
	cout << "\t������� �������������� ��������� ��������� A["<<na<<"]:" << endl;
	for(int i=0;i<na;i++) cin>>a[i];
		
	cout << "\t������� ���������� ��������� ��������� B:" << endl; cin >> nb;
	b = new int[nb+1]; // +1 ��� ������ ������� ���������
	cout << "\t������� �������������� ��������� ��������� B["<<nb<<"]:" << endl;
	for(int i=0;i<nb;i++) cin>>b[i];
		
	cout << "\t������� ���������� ��������� ��������� C:" << endl; cin >> nc;
	c = new int[nc+1]; // +1 ��� ������ ������� ���������
	cout << "\t������� �������������� ��������� ��������� C["<<nc<<"]:" << endl;
	for(int i=0;i<nc;i++) cin>>c[i];
		
	cout << "\t���������������� ����� �������� (0 - ����� �������, 1 - ������������ �����������������):" << endl; cin >> demo;

	clock_t t = clock();

	// ���������� ������ ������ ���� ������������ ��������������� ��������� ��������
	int *ids = new int[na+nb+nc+1]; // ������ ���� ������������ ��������������� +1 ��� ������ ������� ���������
	int count=0; // ���������� ������������ ���������������

	for(int i=0;i<na;i++) {
		int id = a[i];
		int index=count;
		while(index-->0) if(ids[index]==id) break;
		if(index==-1) ids[count++]=id;
	}
	for(int i=0;i<nb;i++) {
		int id = b[i];
		int index=count;
		while(index-->0) if(ids[index]==id) break;
		if(index==-1) ids[count++]=id;
	}
	for(int i=0;i<nc;i++) {
		int id = c[i];
		int index=count;
		while(index-->0) if(ids[index]==id) break;
		if(index==-1) ids[count++]=id;
	}

	// ������������ ������� ��������� �������� ������
	int *va = new int[count+1]; // �������� ������ ������ ��������� A
	int *vb = new int[count+1]; // �������� ������ ������ ��������� B
	int *vc = new int[count+1]; // �������� ������ ������ ��������� C
	
	clear(va, count);
	clear(vb, count);
	clear(vc, count);
	for(int i=0;i<na;i++) {
		int id = a[i];
		int index=count;
		while(index-->0) if(ids[index]==id) break;
		va[index]=1;
	}
	for(int i=0;i<nb;i++) {
		int id = b[i];
		int index=count;
		while(index-->0) if(ids[index]==id) break;
		vb[index]=1;
	}
	for(int i=0;i<nc;i++) {
		int id = c[i];
		int index=count;
		while(index-->0) if(ids[index]==id) break;
		vc[index]=1;
	}

	if(demo!=0){
		cout << "\t������ a:"; for(int i=0;i<count;i++) cout<<va[i]; cout << endl; 
		cout << "\t������ b:"; for(int i=0;i<count;i++) cout<<vb[i]; cout << endl; 
		cout << "\t������ c:"; for(int i=0;i<count;i++) cout<<vc[i]; cout << endl; 
	}

	int *x1 = new int[count+1]; // �������� ������ ������ ����������� �������� A � B
	int *x2 = new int[count+1]; // �������� ������ ������ ����������� �������� A � B
	int *x3 = new int[count+1]; // �������� ������ ������ �������� �������� � � B
	int *x4 = new int[count+1]; // �������� ������ ������ �������� �������� B � A

	or(va, vb, x1, count);
	and(va, vb, x2, count);
	sub(va, vb, x3, count);
	sub(vb, va, x4, count);

	if(demo!=0){
		cout << "\t������ a|b:"; for(int i=0;i<count;i++) cout<<x1[i]; cout << endl; 
		cout << "\t������ a&b:"; for(int i=0;i<count;i++) cout<<x2[i]; cout << endl; 
		cout << "\t������ a-b:"; for(int i=0;i<count;i++) cout<<x3[i]; cout << endl; 
		cout << "\t������ b-a:"; for(int i=0;i<count;i++) cout<<x4[i]; cout << endl; 
	}

	int *y = new int[count+1];

	xor(vc,x1,y, count); 
	if(sum(y,count)==0) cout << "a|b == c"<< endl;
	else cout << "a|b != c"<< endl;

	xor(vc,x2,y, count); 
	if(sum(y,count)==0) cout << "a&b == c"<< endl;
	else cout << "a&b != c"<< endl;

	xor(vc,x3,y, count); 
	if(sum(y,count)==0) cout << "a-b == c"<< endl;
	else cout << "a-b != c"<< endl;

	xor(vc,x4,y, count); 
	if(sum(y,count)==0) cout << "b-a == c"<< endl;
	else cout << "b-a != c"<< endl;

	delete y;
	delete x1;
	delete x2;
	delete x3;
	delete x4;
	delete va;
	delete vb;
	delete vc;
	delete ids;

	t = clock()-t;

	double seconds = ((double)t)/CLOCKS_PER_SEC;
	cout << "\t����� ����������: " << seconds << "sec" << endl;

	delete a;
	delete b;
	delete c;

	getchar();
	getchar();

	return 0;
}

