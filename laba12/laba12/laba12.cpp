#include<iostream>
#include<vector>
#include<ctime>
#include<fstream>
using namespace std;
long long counter = 0;
void Add(vector<vector<int>>& a, vector<vector<int>>& b, vector<vector<int>>& c, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			c[i][j] = a[i][j] + b[i][j];
			counter += 2;
		}
	}
}
void Sub(vector<vector<int>>& a, vector<vector<int>>& b, vector<vector<int>>& c, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			c[i][j] = a[i][j] - b[i][j];
			counter += 2;
		}
	}
}
void Multi(vector<vector<int>>&a, vector<vector<int>>&b, vector<vector<int>>&c, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				c[i][j] += a[i][k] * b[k][j];
				counter += 2;
			}
		}
	}
}
void Split(vector<vector<int>>& a, vector<vector<int>>& b, int row, int col, int n)
{
	for (int i = 0,i1=row; i < n; i++,i1++)
	{
		for (int j = 0,j1=col; j < n; j++,j1++)
		{
			b[i][j] = a[i1][j1];
			counter++;
		}
	}
}
void Union(vector<vector<int>>& a, vector<vector<int>>& b, int row, int col, int n)
{
	for (int i = 0, i1 = row; i < n; i++, i1++)
	{
		for (int j = 0, j1 = col; j < n; j++, j1++)
		{
			b[i1][j1] = a[i][j];
			counter++;
		}
	}
}
void Strassen(vector<vector<int>>& a, vector<vector<int>>& b, vector<vector<int>>& c, int n)
{
	int n1 = n / 2;
	counter += 2;
	vector<int>inside(n1);
	vector<vector<int>>a11(n1, inside);
	vector<vector<int>>a12(n1, inside);
	vector<vector<int>>a21(n1, inside);
	vector<vector<int>>a22(n1, inside);
	vector<vector<int>>b11(n1, inside);
	vector<vector<int>>b12(n1, inside);
	vector<vector<int>>b21(n1, inside);
	vector<vector<int>>b22(n1, inside);
	vector<vector<int>>c11(n1, inside);
	vector<vector<int>>c12(n1, inside);
	vector<vector<int>>c21(n1, inside);
	vector<vector<int>>c22(n1, inside);

	Split(a, a11, 0, 0, n1);
	Split(a, a12, 0, n1, n1);
	Split(a, a21, n1, 0, n1);
	Split(a, a22, n1, n1, n1);
	Split(b, b11, 0, 0, n1);
	Split(b, b12, 0, n1, n1);
	Split(b, b21, n1, 0, n1);
	Split(b, b22, n1, n1, n1);

	vector<vector<int>>res1(n1, inside);
	vector<vector<int>>res2(n1, inside);

	Add(a11, a22, res1, n1);
	Add(b11, b22, res2, n1);
	vector<vector<int> > p1(n1, inside);
	Multi(res1, res2, p1, n1);

	Add(a21, a22, res1, n1);
	vector< vector<int> > p2(n1, inside);
	Multi(res1, b11, p2, n1);

	Sub(b12, b22, res2, n1);
	vector< vector<int> > p3(n1, inside);
	Multi(a11, res2, p3, n1);

	Sub(b21, b11, res2, n1);
	vector< vector<int> > p4(n1, inside);
	Multi(a22, res2, p4, n1);

	Add(a11, a12, res1, n1);
	vector< vector<int> > p5(n1, inside);
	Multi(res1, b22, p5, n1);

	Sub(a21, a11, res1, n1);
	Add(b11, b12, res2, n1);
	vector< vector<int> > p6(n1, inside);
	Multi(res1, res2, p6, n1);

	Sub(a12, a22, res1, n1);
	Add(b21, b22, res2, n1);
	vector< vector<int> > p7(n1, inside);
	Multi(res1, res2, p7, n1);

	// c11
	Add(p1, p4, res1, n1);
	Add(res1, p7, res2, n1);
	Sub(res2, p5, c11, n1);

	// c12
	Add(p3, p5, c12, n1);

	// c21
	Add(p2, p4, c21, n1);

	// c22
	Sub(p1, p2, res1, n1);
	Add(p3, p6, res2, n1);
	Add(res1, res2, c22, n1);

	Union(c11, c,n1,0,0);
	Union(c12, c,n1,0,n1);
	Union(c21, c,n1,n1,0);
	Union(c22, c,n1,n1,n1);

}
int main()
{
	ofstream f("answ.txt");
	srand(time(0));
	for (int n = 4; n <= 1024; n*=2)
	{
		vector<int>inside(n);//строки для каждой матрицы
		vector<vector<int>>a(n, inside);
		vector<vector<int>>b(n, inside);
		vector<vector<int>>c(n, inside);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				a[i][j] =rand() % 10;
				b[i][j] =rand() % 10;
			}
		}
		/*cout <<endl<< "Multi: " << endl;
		Multi(a, b, c, n);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << c[i][j] << " ";
			}
			cout << endl;
		}*/
		//cout <<endl<< "Strassen: " << endl;
		Strassen(a, b, c, n);
		cout << "n= " << n << " " << counter<<endl;
		f << "n= " << n << " " << counter<<endl;
		counter = 0;
		/*for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << c[i][j] << " ";
			}
			cout << endl;
		}*/
	}
}