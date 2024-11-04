#include<iostream>
#include<vector>
#include<cmath>
#include<fstream>
#include<iomanip>
using namespace std;

//int determ(vector<vector<double>>& a)
//{
//    double tmp = 0,d=0;
//    int n = a.size();
//    for (int k = 0; k < n - 1; k++) {
//        for (int i = k + 1; i < n; i++) {
//            tmp = -a[i][k] / a[k][k];
//            for (int j = 0; j < n; j++) {
//                a[i][j] += a[k][j] * tmp;
//            }
//        }
//    }
//    d = 1;
//    for (int i = 0; i < n; i++) {
//        d *= a[i][i];
//    }
//    return d;
//}
//int rangplus(vector<vector<double>>& matrix, vector<vector<double>>& submatrix, vector<double>& plus,int k)
//{
//    int n = matrix.size();
//
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            if (j == k)
//            {
//                submatrix[i][j] = plus[i];
//            }
//        }
//    }
//    if (determ(submatrix) == 0)
//    {
//        return 2;
//    }
//    else
//    {
//        return 3;
//    }
//}
//int maxrang(vector<int> r)
//{
//    int n = r.size();
//    int max = r[0];
//    for (int i = 0; i < n; i++)
//    {
//        if (r[i] > max)
//        {
//            max = r[i];
//        }
//    }
//    return max;
//}
//int main()
//{
//	int n = 3;
//    vector<vector<double>> aplus1 (n, vector<double>(n));
//    vector<vector<double>> aplus2 (n, vector<double>(n));
//    vector<vector<double>> aplus3 (n, vector<double>(n));
//	vector<vector<double>> a(n, vector<double>(n));
//    vector<double> plus(3);
//    vector<int> r(4);
//	    cout << "Enter a: ";
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			cin >> a[i][j];
//		}
//	}
//    cout << "\nEnter a Plus: ";
//    for (int j = 0; j < n; j++)
//    {
//        cin>>plus[j];
//    }
//    int rang;
//    if (determ(a) == 0)
//    {
//        rang = 2;
//    }
//    else
//    {
//        rang = 3;
//    }
//    aplus1 = aplus2 = aplus3 = a;
//    r[0] = rang;
//    r[1] = rangplus(a, aplus1, plus, 0);
//    r[2] = rangplus(a, aplus1, plus, 1);
//    r[3] = rangplus(a, aplus1, plus, 2);
//    int rang1 = maxrang(r);
//    cout << "Rang: " << rang << endl;
//    cout << "Rang Plus: " << rang1 << endl;
//    if (rang == rang1) {
//        cout << "sovmesno\n";
//        if (rang < n) cout << "edinstv\n";
//        else
//            cout << "Mnogo\n";
//    }
//
//}

//0.1
//0.2
//0.3
//0.4
//0.5
//0.6
//0.7
//0.8
//0.9

//#include <iostream>
//#include <fstream>
//
//const int n = 4;
//double skalpr(const double* a, const double* b)
//{
//    double result = 0;
//    for (int i = 0; i < n; i++)
//    {
//        result += a[i] * b[i];
//    }
//    return result;
//}
//
//double maxost(const double* res)
//{
//    double maxch = fabs(res[0]);
//    for (int i = 1; i < n; i++) {
//        if (fabs(res[i]) > maxch)
//        {
//            maxch = fabs(res[i]);
//        }
//    }
//    return maxch;
//}
//
//void jacobi(const double A[n][n], const double b[n], double x[n], double eps)
//{
//    double x_old[n];
//    int k = 0;
//    double res[n];
//
//    ofstream jacobi_file("jacobi_iterations.txt");
//
//    while (true)
//    {
//        for (int i = 0; i < n; i++)
//        {
//            x_old[i] = x[i];
//        }
//
//        k++;
//        jacobi_file << "Итерация " << k << ": ";
//        for (int i = 0; i < n; i++)
//        {
//            double sum = 0;
//            for (int j = 0; j < n; j++)
//            {
//                if (j != i) {
//                    sum += A[i][j] * x_old[j];
//                }
//            }
//            x[i] = (b[i] - sum) / A[i][i];
//            jacobi_file << x[i] << " ";
//        }
//        jacobi_file << endl;
//
//        for (int i = 0; i < n; i++)
//        {
//            res[i] = b[i] - skalpr(A[i], x);
//        }
//
//        if (maxost(res) < eps) break;
//
//        // Записываем норму невязки и номер итерации в файл
//        jacobi_file << "Норма невязки: " << maxost(res) << ", Итерация: " << k << endl;
//    }
//
//    jacobi_file.close();
//    cout << "\nМетод Якоби" << endl;
//    cout << "Решение:" << endl;
//    for (int i = 0; i < n; i++)
//    {
//        cout << x[i] << " ";
//    }
//    cout << endl;
//    cout << "Кол-во итераций: " << k << endl;
//}
//
//void seidel(const double A[n][n], const double b[n], double x[n], double eps) {
//    double x_old[n];
//    int k = 0;
//    double res[n];
//
//    ofstream seidel_file("seidel_iterations.txt");
//
//    while (true)
//    {
//        for (int i = 0; i < n; i++)
//        {
//            x_old[i] = x[i];
//        }
//
//        k++;
//        seidel_file << "Итерация " << k << ": ";
//        for (int i = 0; i < n; i++)
//        {
//            double sum1 = 0, sum2 = 0;
//            for (int j = 0; j < i; j++)
//            {
//                sum1 += A[i][j] * x[j];
//            }
//            for (int j = i + 1; j < n; j++)
//            {
//                sum2 += A[i][j] * x_old[j];
//            }
//            x[i] = (b[i] - sum1 - sum2) / A[i][i];
//            seidel_file << x[i] << " ";
//        }
//        seidel_file << endl;
//
//        for (int i = 0; i < n; i++)
//        {
//            res[i] = b[i] - skalpr(A[i], x);
//        }
//
//        if (maxost(res) < eps) break;
//
//        // Записываем норму невязки и номер итерации в файл
//        seidel_file << "Норма невязки: " << maxost(res) << ", Итерация: " << k << endl;
//    }
//
//    seidel_file.close();
//    cout << "\nМетод Зейделя" << endl;
//    cout << "Решение:" << endl;
//    for (int i = 0; i < n; i++)
//    {
//        cout << x[i] << " ";
//    }
//    cout << endl;
//    cout << "Кол-ко итераций: " << k << endl;
//}
//
//int main()
//{
//    setlocale(LC_ALL, "RUS");
//    double A[n][n] = { {12.14, 1.32, -0.78, -2.75},
//                       {-0.89, 16.75, 1.88, -1.55},
//                       {2.65, -1.27, -15.64, -0.64},
//                       {2.44, 1.52, 1.93, -11.43} };
//
//    double b[n] = { 14.78, -12.14, -11.65, 4.26 };
//    double x[n] = { 1 ,1,1,1};
//    double eps = 1e-10;
//
//    cout << "Начальные приближения:" << endl;
//    for (int i = 0; i < n; i++)
//    {
//        cout << x[i] << " ";
//    }
//    cout << endl;
//
//    jacobi(A, b, x, eps);
//    seidel(A, b, x, eps);
//
//    return 0;
//}

//5.1
//1

double func(double x) {
	return 1 / (1 + 25 * x * x);
}
double interpol(double* x,double* y, double z, int n) {
	float S = 0.0;

	for (int i = 0; i <= n; ++i)
	{
		float  P = 1.0;
		for (int j = 0; j <= n; ++j)
		{
			if (x[i] != x[j])
			{
				P *= (z - x[j]) / (x[i] - x[j]);
			}
		}
		S = S + y[i] * P;
	}
	return S;
}
int main() {
	ofstream f;
	f.open("Function.txt");
	int n = 20;
	double xi = -1;
	double* x = new double [n];
	double* y = new double[n];
	double* s = new double[n];
	for (int i = 0; i <= n; i++)
	{
		x[i] = xi;
		xi += 0.1;
		y[i] = func(x[i]);
		s[i] = interpol(x, y, x[i], n);
		cout << fixed << setprecision(1) << x[i] << fixed << setprecision(10) << " " << y[i] << " " <<s[i]<<endl;
		f << fixed << setprecision(1) << x[i] << fixed << setprecision(10) << " " << y[i] << " " << s[i] << endl;
	}
	f.close();
}


