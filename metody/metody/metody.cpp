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
//#include <cmath>
//#include <vector>
//#include <fstream> 
//using namespace std;
//
//const double eps = 1e-6;
//const int max_it = 100;
//
//void jacobi(const vector<vector<double>>& a, const vector<double>& b, vector<double>& x0) {
//    vector<int> X;
//    vector<double> Y;
//    int n = a.size();
//    vector<double> x(n);
//    int it = 0;
//    double norm;
//
//    do {
//        norm = 0.0;
//        for (int i = 0; i < n; i++) {
//            x[i] = b[i];
//            for (int j = 0; j < n; j++) {
//                if (i != j) {
//                    x[i] -= a[i][j] * x0[j];
//                }
//            }
//            x[i] /= a[i][i];
//        }
//
//        for (int i = 0; i < n; i++) {
//            norm += fabs(x[i] - x0[i]);
//        }
//
//        x0 = x;
//        it++;
//        cout << "Итерация " << it << ": Норма невязки = " << norm << endl;
//        X.push_back(it);
//        Y.push_back(norm);
//
//    } while (norm > eps && it < max_it);
//
//    cout << "Решение методом Якоби: ";
//    for (double xi : x) {
//        cout << xi << " ";
//    }
//    cout << endl;
//    ofstream outFile("jacobi_res.txt");
//
//    if (!outFile) {
//        cerr << "Не удалось открыть файл" << endl;
//        return;
//    }
//
//    for (auto i : X) outFile << i << " ";
//    outFile << endl;
//    for (auto i : Y) outFile << i << " ";
//    outFile.close();
//}
//
//void zeidel(const vector<vector<double>>& a, const vector<double>& b, vector<double>& x0) {
//    vector<int> X;
//    vector<double> Y;
//    int n = a.size();
//    vector<double> x(n);
//    int it = 0;
//    double norm;
//
//    do {
//        norm = 0.0;
//        for (int i = 0; i < n; i++) {
//            x[i] = b[i];
//            for (int j = 0; j < n; j++) {
//                if (j < i) {
//                    x[i] -= a[i][j] * x[j];
//                }
//                else if (j > i) {
//                    x[i] -= a[i][j] * x0[j];
//                }
//            }
//            x[i] /= a[i][i];
//        }
//
//        for (int i = 0; i < n; i++) {
//            norm += fabs(x[i] - x0[i]);
//        }
//
//        x0 = x;
//        it++;
//        cout << "Итерация " << it << ": Норма невязки = " << norm << endl;
//        X.push_back(it);
//        Y.push_back(norm);
//
//    } while (norm > eps && it < max_it);
//
//    cout << "Решение методом Зейделя: ";
//    for (double xi : x) {
//        cout << xi << " ";
//    }
//    cout << endl;
//    ofstream outFile("zeidel_res.txt");
//
//    if (!outFile) {
//        cerr << "Не удалось открыть файл для записи!" << endl;
//        return;
//    }
//    for (auto i : X) outFile << i << " ";
//    outFile << endl;
//    for (auto i : Y) outFile << i << " ";
//    outFile.close();
//}
//
//int main() {
//    setlocale(LC_ALL, "");
//    vector<vector<double>> a = {
//        {12.14, 1.32, -0.78, -2.75},
//        {-0.89, 16.75, 1.88, -1.55},
//        {2.65, -1.27, -15.64, -0.64},
//        {2.44, 1.52, 1.93, -11.43}
//    };
//    vector<double> b = { 14.78, -12.14, -11.65, 4.26 };
//    vector<double> x0 = { 0, 0, 0, 0 };
//
//    jacobi(a, b, x0);
//    cout << endl << endl;
//
//    x0 = { 0, 0, 0, 0 };
//
//    zeidel(a, b, x0);
//    return 0;
//}

//5.1

//1

//double func(double x) {
//	return 1 / (1 + 25 * x * x);
//}
//double func2(int i) {
//	double a = -1.0;
//	double b = 1.0;	
//	double n = 20;
//	double PI = 3.1415926535;
//	return (a+b)/2+((b-a)/2)* cos(((2 * i - 1) / (2 * n)) * PI);;
//}
//double interpol(double* x,double* y, double z, int n) {
//	float S = 0.0;
//
//	for (int i = 0; i <= n; ++i)
//	{
//		float  P = 1.0;
//		for (int j = 0; j <= n; ++j)
//		{
//			if (x[i] != x[j])
//			{
//				P *= (z - x[j]) / (x[i] - x[j]);
//			}
//		}
//		S = S + y[i] * P;
//	}
//	return S;
//}
//int main() {
//	ofstream f;
//	f.open("Function.txt");
//	int n = 20;
//	double* x = new double [n];
//	double* y = new double[n];
//	double* s = new double[n];
//	double PI = 3.1415926535;
//	for (int i = 0; i <= n; i++)
//	{
//		double xi = func2(i);
//		x[i] = xi;
//		//xi += 0.1;
//		y[i] = func(x[i]);
//		s[i] = interpol(x, y, x[i], n);
//		cout << x[i] << fixed << setprecision(10) << " " << y[i] << " " <<s[i]<<endl;
//		f << x[i] << fixed << setprecision(10) << " " << y[i] << " " << s[i] << endl;
//	}
//	f.close();
//}

//2

//double func(double x) {
//	return 1 / (1 + 25 * x * x);
//}
//double splain(double* x,double* y, double z, int n) {
//	
//}
//int main() {
//	ofstream f;
//	f.open("Function.txt");
//	int n = 20;
//	double* x = new double [n];
//	double* y = new double[n];
//	double* s = new double[n];
//	double PI = 3.1415926535;
//	for (int i = 0; i <= n; i++)
//	{
//		double xi;
//		xi += 0.1;
//		y[i] = func(x[i]);
//		s[i] = splain(x, y, x[i], n);
//		cout << x[i] << fixed << setprecision(10) << " " << y[i] << " " <<s[i]<<endl;
//		f << x[i] << fixed << setprecision(10) << " " << y[i] << " " << s[i] << endl;
//	}
//	f.close();
//}




//5.2

//#include <iostream>
//#include <cmath>
//#include <vector>
//#include <fstream>
//#include <iomanip>
//using namespace std;
//
//int main() {
//    setlocale(LC_ALL, "");
//    vector<double> x = { 1, 2, 3, 4, 5, 6 };
//    vector<double> y = { 2.0, 0.68, 0.44, 0.24, 0.12, 0.14 };
//
//    int n = x.size();
//    double sum_x = 0, sum_y = 0, sum_xy = 0, sum_xx = 0;
//    for (int i = 0; i < n; i++) {
//        sum_x += x[i];
//        sum_y += y[i];
//        sum_xy += x[i] * y[i];
//        sum_xx += x[i] * x[i];
//    }
//    // Lin func
//    double a = (n * sum_xy - sum_x * sum_y) / (n * sum_xx - sum_x * sum_x);
//    double b = (sum_y - a * sum_x) / n;
//    a = round(a * 100.0) / 100.0;
//    b = round(b * 100.0) / 100.0;
//    cout << "a = " << a << endl;
//    cout << "b = " << b << endl;
//
//    ofstream outputFile("results.txt");
//    if (outputFile.is_open()) {
//        // Записываем экспериментальные точки
//        outputFile << "Экспериментальные точки:\n";
//        for (int i = 0; i < n; i++) {
//            outputFile << "x: " << x[i] << " y: " << y[i] << endl;
//        }
//        outputFile << "Для линейной функции: \n";
//        outputFile << "\nАппроксимирующая функция: y = " << a << " * x + " << b << endl;
//        outputFile << "\nГрафик:\n";
//        for (double xi = 1; xi <= 6; xi += 0.1) {
//            double yi = a * xi + b;
//            outputFile << "x: " << setprecision(4) << xi << " y: " <<
//                setprecision(4) << yi << endl;
//        }
//
//        outputFile << "\nСтепенная функция: y = " << a << " * x^" << b << "\n";
//        outputFile << "График:\n";
//        for (double xi = 1; xi <= 6; xi += 0.1) {
//            double yi = pow(xi, b) * a;
//            outputFile << "x: " << setprecision(4) << xi << " y: " << setprecision(4) << yi << "\n";
//        }
//
//        outputFile << "\nПоказательная функция: y = " << a << " * e^(" << b << " * x)\n";
//        outputFile << "График:\n";
//        for (double xi = 1; xi <= 6; xi += 0.1) {
//            double yi = a * exp(b * xi);
//            outputFile << "x: " << setprecision(4) << xi << " y: " << setprecision(4) << yi << "\n";
//        }
//
//        outputFile << "\nКвадратичная функция: y = " << a << " + " << b << " * x + " << b << " * x^2\n";
//        outputFile << "График:\n";
//        for (double xi = 1; xi <= 6; xi += 0.1) {
//            double yi = a + b * xi + b * xi * xi;
//            outputFile << "x: " << setprecision(4) << xi << " y: " << setprecision(4) << yi << "\n";
//        }
//
//        outputFile.close();
//    }
//    else {
//        cout << "Не удалось открыть файл для записи." << endl;
//    }
//    return 0;
//}

//6

//#include <ctime>
//double func(double x, double n) {
//	if (x >= 0 && x < n)
//		return (10 * x) / n;
//	else
//		return 10 * ((x - 20) / (n - 20));
//}
//double max(double* x, double n)
//{
//	double maxim = x[0];
//	for (int i = 0; i < n; i++)
//	{
//		if (x[i] > maxim) {
//			maxim = x[i];
//		}
//	}
//	return maxim;
//}
//int main()
//{
//	ofstream f;
//	f.open("MonteCarlo.txt");
//	srand(time(NULL));
//	int n = 101;
//	double* x = new double[n];
//	double* y = new double[n];
//	double* xMC = new double[n];
//	double* yMC = new double[n];
//	for (int i = 0; i < n; i++)
//	{
//		x[i] = i * 0.2;
//		y[i] = func(x[i], 5);
//	}
//	double a = max(x, 100);
//	double b = max(y, 100);
//	for (int i = 0; i < n; i++)
//	{
//		xMC[i] = (double)rand() / (double)RAND_MAX * a;
//		yMC[i] = (double)rand() / (double)RAND_MAX * b;
//		cout << xMC[i] << " " << yMC[i] <<"         "<<x[i]<<" "<<y[i]<< endl;
//		f << xMC[i] << " " << yMC[i] << "         " << x[i] << " " << y[i] << endl;
//	}
//	double K = 0;
//	for (int i = 0; i < n; i++)
//	{
//		if (yMC[i] <= func(xMC[i],5))
//			K++;
//	}
//	double S = a * b;
//	K /= 100;
//	double otvet = S * K;
//	cout << otvet<<" "<<fabs(100-otvet);
//	f.close();
//}

//6.2

//#include <iostream>
//#include <random>
//#include <iomanip>
//#include <fstream>
//#include <vector>
//#include <cmath>
//
//using namespace std;
//
//// Параметр из условия задачи
//const int n = 5;
//
//// Подынтегральная функция sqrt(11-n*sin^2(x))
//double f(double x) {
//    return sqrt(11 - n * sin(x) * sin(x));
//}
//
//// Запись точек в файл txt
//void save_points_txt(const vector<pair<double, double>>& inside, const vector<pair<double, double>>& outside, const string& filename) {
//    ofstream file(filename);
//    if (!file.is_open()) {
//        cout << "Ошибка при открытии файла для записи точек." << endl;
//        return;
//    }
//
//    file << "Точки внутри графика функции:" << endl;
//    for (const auto& p : inside) {
//        file << "x = " << p.first << " y = " << p.second << endl;
//    }
//
//    file << "\nТочки вне графика функции:" << endl;
//    for (const auto& p : outside) {
//        file << "x = " << p.first << " y = " << p.second << endl;
//    }
//}
//
//// Запись случайных точек и значений подинтегральной функции в файл txt
//void save_random_points_and_function_values_txt(const vector<pair<double, double>>& points, const string& filename) {
//    ofstream file(filename);
//    if (!file.is_open()) {
//        cout << "Ошибка при открытии файла для записи случайных точек и значений функции." << endl;
//        return;
//    }
//
//    file << "Случайные точки и значения подинтегральной функции:" << endl;
//    for (const auto& point : points) {
//        file << "x = " << point.first << " y = " << point.second << " f(x) = " << f(point.first) << endl;
//    }
//}
//
//int main() {
//    setlocale(LC_ALL, "rus");
//    // 1. Определяем пределы интегрирования
//    const double a = 0;  // нижний предел
//    const double b = 5;  // верхний предел
//
//    // Находим максимум подынтегральной функции на отрезке [a,b]
//    double max_y = 0;
//    for (double x = a; x <= b; x += 0.01) {
//        max_y = max(max_y, f(x));
//    }
//
//    // 2. Выбираем количество случайных точек N
//    const int N = 1000;
//
//    // 3. Генерируем N случайных точек
//    random_device rd;
//    mt19937 gen(rd());
//    uniform_real_distribution<> dist_x(a, b);      // x ∈ [a, b]
//    uniform_real_distribution<> dist_y(0, max_y);  // y ∈ [0, max_y]
//
//    // Векторы для хранения точек (для визуализации)
//    vector<pair<double, double>> points_inside, points_outside;
//
//    // 4. Подсчитываем количество точек M под графиком функции и сохраняем все точки
//    int M = 0;
//    vector<pair<double, double>> all_points;
//    for (int i = 0; i < N; i++) {
//        double x_i = dist_x(gen);
//        double y_i = dist_y(gen);
//
//        // Проверяем условие y_i < f(x_i)
//        if (y_i <= f(x_i)) {
//            M++;
//            points_inside.push_back({ x_i, y_i });
//        }
//        else {
//            points_outside.push_back({ x_i, y_i });
//        }
//
//        all_points.push_back({ x_i, y_i });
//    }
//
//    // 5. Вычисляем интеграл по формуле I ≈ M/N * (b-a)*max_y
//    double I = (static_cast<double>(M) / N) * (b - a) * max_y;
//
//    // 6. Оцениваем погрешности
//    double p = M / static_cast<double>(N);  // вероятность попадания под график
//    double variance = p * (1 - p);  // дисперсия
//    double abs_error = sqrt(variance / N) * (b - a) * max_y;  // абсолютная погрешность
//    double rel_error = (abs_error / I) * 100;  // относительная погрешность
//
//    // Выводим результаты
//    cout << fixed << setprecision(6);
//    cout << "Значение интеграла: " << I << endl;
//    cout << "Абсолютная погрешность: " << abs_error << endl;
//    cout << "Относительная погрешность: " << rel_error << endl;
//
//    // Сохраняем точки для визуализации
//    save_points_txt(points_inside, points_outside, "points.txt");
//
//    // Сохраняем все случайные точки и значения функции
//    save_random_points_and_function_values_txt(all_points, "random_points_and_function_values.txt");
//
//    return 0;
//}

//6.3

//#include <iostream>
//#include <random>
//#include <iomanip>
//#include <fstream>
//#include <vector>
//#include <cmath>
//
//using namespace std;
//
//// Параметр из условия задачи
//const int n = 5;  // R = n
//
//// Запись координаты радиуса и случайных точек в файл txt
//void save_radius_and_random_points(const vector<pair<double, double>>& points, const string& filename) {
//    ofstream file(filename);
//    if (!file.is_open()) {
//        cout << "Ошибка при открытии файла для записи координаты радиуса и случайных точек." << endl;
//        return;
//    }
//
//    file << "Радиус R = " << n << endl;
//    file << "Координаты случайно выбранных точек:" << endl;
//    for (const auto& point : points) {
//        file << "xi = " << point.first << " yi = " << point.second << endl;
//    }
//}
//
//int main() {
//    setlocale(LC_ALL, "rus");
//    // 1. Определяем радиус R = n
//    const double R = n;
//
//    // 2. Выбираем количество случайных точек N
//    const int N = 100000;
//
//    // 3. Генерируем N случайных точек в квадрате [-R,R]×[-R,R]
//    random_device rd;
//    mt19937 gen(rd());
//    uniform_real_distribution<> dist(-R, R);  // x,y ∈ [-R,R]
//
//    // Векторы для хранения точек (для визуализации)
//    vector<pair<double, double>> points_inside, points_outside;
//
//    // 4. Подсчитываем количество точек M внутри круга
//    int M = 0;  // количество точек внутри круга
//    vector<pair<double, double>> all_points;
//    for (int i = 0; i < N; i++) {
//        double x_i = dist(gen);
//        double y_i = dist(gen);
//
//        // Проверяем условие (x_i)^2 + (y_i)^2 ≤ R^2
//        if (x_i * x_i + y_i * y_i <= R * R) {
//            M++;
//            points_inside.push_back({ x_i, y_i });
//        }
//        else {
//            points_outside.push_back({ x_i, y_i });
//        }
//
//        all_points.push_back({ x_i, y_i });
//    }
//
//    // 5. Вычисляем π ≈ 4M/N
//    double pi = 4.0 * M / N;
//
//    // 6. Оцениваем погрешности
//    double p = M / static_cast<double>(N);  // вероятность попадания в круг
//    double variance = p * (1 - p);  // дисперсия
//    double abs_error = 4.0 * sqrt(variance / N);  // абсолютная погрешность
//    double rel_error = (abs_error / pi) * 100;  // относительная погрешность
//
//    // Выводим результаты
//    cout << fixed << setprecision(6);
//    cout << "Значение числа π (метод Монте-Карло): " << pi << endl;
//    cout << "Абсолютная погрешность: " << abs_error << endl;
//    cout << "Относительная погрешность: " << rel_error << endl;
//
//    // Сохраняем координаты радиуса и случайные точки в файл txt
//    save_radius_and_random_points(all_points, "radius_and_random_points.txt");
//
//    return 0;
//}

//6.4

//#include <iostream>
//#include <random>
//#include <iomanip>
//#include <fstream>
//#include <vector>
//#include <cmath>
//#define _USE_MATH_DEFINES
//#include <math.h>
//
//using namespace std;
//
//// Параметр из условия задачи
//const int n = 5;
//const double A = 11 + n;  // A = 11 + n
//const double B = 11 - n;  // B = 11 - n
//
//// Функция p(t) в полярных координатах
//double p(double t) {
//    return sqrt(A * cos(t) * cos(t) + B * sin(t) * sin(t));
//}
//
//// Запись точек в файл txt
//void save_points(const vector<pair<double, double>>& inside, const vector<pair<double, double>>& outside) {
//    ofstream in_file("points_inside.txt"), out_file("points_outside.txt");
//    if (!in_file.is_open() || !out_file.is_open()) {
//        cout << "Ошибка при открытии файла для записи точек." << endl;
//        return;
//    }
//
//    in_file << "Точки внутри фигуры:" << endl;
//    out_file << "Точки вне фигуры:" << endl;
//    for (const auto& p : inside) {
//        in_file << "x = " << p.first << " y = " << p.second << endl;
//    }
//    for (const auto& p : outside) {
//        out_file << "x = " << p.first << " y = " << p.second << endl;
//    }
//}
//
//int main() {
//    setlocale(LC_ALL, "rus");
//    // 1. Находим максимальное значение p(t)
//    double max_p = 0;
//    for (double t = 0; t < 2 * M_PI; t += 0.01) {
//        max_p = max(max_p, p(t));
//    }
//
//    // Определяем размеры прямоугольника [-a,a]×[-b,b]
//    const double a = max_p;
//    const double b = max_p;
//
//    // 2. Выбираем количество случайных точек N
//    const int N = 1000;
//
//    // 3. Генерируем N случайных точек
//    random_device rd;
//    mt19937 gen(rd());
//    uniform_real_distribution<> dist_x(-a, a);  // x ∈ [-a,a]
//    uniform_real_distribution<> dist_y(-b, b);  // y ∈ [-b,b]
//
//    // Векторы для хранения точек (для визуализации)
//    vector<pair<double, double>> points_inside, points_outside;
//
//    // 4. Подсчитываем количество точек M внутри фигуры
//    int M = 0;  // количество точек внутри фигуры
//    for (int i = 0; i < N; i++) {
//        double x = dist_x(gen);
//        double y = dist_y(gen);
//
//        // Перевод в полярные координаты
//        double r = sqrt(x * x + y * y);
//        double t = atan2(y, x);
//        if (t < 0) t += 2 * M_PI;  // приводим к [0, 2π]
//
//        // Проверяем условие r ≤ p(t)
//        if (r <= p(t)) {
//            M++;
//            points_inside.push_back({ x, y });
//        }
//        else {
//            points_outside.push_back({ x, y });
//        }
//    }
//    cout << M<<endl;
//    // 5. Вычисляем площадь S = M/N * (2a)*(2b)
//    double S = (static_cast<double>(M) / N) * (2 * a) * (2 * b);
//
//    // 6. Оцениваем погрешности
//    double p_prob = M / static_cast<double>(N);  // вероятность попадания в фигуру
//    double variance = p_prob * (1 - p_prob);  // дисперсия
//    double abs_error = sqrt(variance / N) * (2 * a) * (2 * b);  // абсолютная погрешность
//    double rel_error = (abs_error / S) * 100;  // относительная погрешность
//
//    // Выводим результаты
//    cout << fixed << setprecision(6);
//    cout << "Площадь фигуры (метод Монте-Карло): " << S << endl;
//    cout << "Абсолютная погрешность: " << abs_error << endl;
//    cout << "Относительная погрешность: " << rel_error << endl;
//
//    // сохраняем точки для визуализации
//    save_points(points_inside, points_outside);
//
//    return 0;
//}

//7.1

//#include <iostream>
//#include <iomanip>
//#include <cmath>
//#include <vector>
//#include <fstream>
//#define _USE_MATH_DEFINES
//#include <math.h>
//
//using namespace std;
//
//// Подынтегральная функция e^(-t^2)
//double f(double t) {
//    return exp(-t * t);
//}
//
//// Метод прямоугольников
//double rectangle_method(double a, double b, int n) {
//    double h = (b - a) / n;
//    double sum = 0.0;
//
//    for (int i = 0; i < n; i++) {
//        double x = a + i * h;
//        sum += f(x);
//    }
//
//    return h * sum;
//}
//
//// Метод трапеций
//double trapezoid_method(double a, double b, int n) {
//    double h = (b - a) / n;
//    double sum = (f(a) + f(b)) / 2.0;
//
//    for (int i = 1; i < n; i++) {
//        double x = a + i * h;
//        sum += f(x);
//    }
//
//    return h * sum;
//}
//
//// Метод Симпсона
//double simpson_method(double a, double b, int n) {
//    if (n % 2 != 0) n++; // n должно быть четным
//
//    double h = (b - a) / n;
//    double sum = f(a) + f(b);
//
//    for (int i = 1; i < n; i++) {
//        double x = a + i * h;
//        sum += f(x) * (i % 2 == 0 ? 2 : 4);
//    }
//
//    return h * sum / 3.0;
//}
//
//// Вычисление erf(x) = (2/sqrt(π)) * ∫[0 to x] e^(-t^2)dt
//double erf(double x, int n = 1000) {
//    const double PI = 3.14159265358979323846;
//    return (2.0 / sqrt(PI)) * simpson_method(0, x, n);
//}
//
//// Функция для вычисления erf(x) методом прямоугольников
//double rectangular_erf(double x, int n) {
//    return (2.0 / sqrt(M_PI)) * rectangle_method(0, x, n);
//}
//
//// Функция для вычисления erf(x) методом трапеций
//double trapezoidal_erf(double x, int n) {
//    return (2.0 / sqrt(M_PI)) * trapezoid_method(0, x, n);
//}
//
//// Функция для вычисления erf(x) методом Симпсона
//double simpson_erf(double x, int n) {
//    return (2.0 / sqrt(M_PI)) * simpson_method(0, x, n);
//}
//
//struct ErfEntry {
//    double x;
//    double value;
//};
//
//const vector<ErfEntry> erf_table = {
//    {0.0, 0.0},
//    {0.5, 0.5204998778130465},
//    {1.0, 0.8427007861273222},
//    {1.5, 0.9661051464753109},
//    {2.0, 0.9953222650189527},
//    {2.5, 0.9995930488505496},
//    { 3.0, 0.9999779095030014 }, 
//    { 3.5, 0.9999997138536045 },
//    { 4.0, 0.9999999847691296 }
//};
//
//int main() {
//    // Открываем файл для записи результатов
//    ofstream out("erf_values.txt");
//    out << "x\trectangular\trapezoidal\tsimpson\ttable_value\tdescription\n";
//
//    // Устанавливаем точность вывода
//    cout << fixed << setprecision(10);
//
//    // Диапазон значений для исследования
//    double start = 0.0, end = 4.0;
//    int n_start = 10, n_end = 1000, n_step = 10;
//
//    // Заголовок таблицы
//    cout << setw(10) << "x"
//        << setw(20) << "Rectangular"
//        << setw(20) << "Trapezoidal"
//        << setw(20) << "Simpson"
//        << setw(20) << "Table Value";
//    cout << endl;
//
//    // Итерация по различным значениям x
//    for (double x = start; x <= end; x += 0.1) {
//        // Находим табличное значение
//        double table_value = 0.0;
//        string description = "";
//        for (const auto& entry : erf_table) {
//            if (fabs(entry.x - x) < 1e-10) {
//                table_value = entry.value;
//                break;
//            }
//        }
//
//        // Вычисляем значения различными методами
//        double rectangular = rectangular_erf(x, n_end);
//        double trapezoidal = trapezoidal_erf(x, n_end);
//        double simpson = simpson_erf(x, n_end);
//
//        // Выводим результаты в консоль
//        cout << setw(10) << x
//            << setw(20) << rectangular
//            << setw(20) << trapezoidal
//            << setw(20) << simpson
//            << setw(20) << table_value
//            << setw(30) << description << endl;
//
//        // Записываем результаты в TXT файл
//        out << x << "\t"
//            << rectangular << "\t"
//            << trapezoidal << "\t"
//            << simpson << "\t"
//            << table_value << "\t"
//            << description << endl;
//    }
//
//    out.close();
//
//    return 0;
//}

//7.1.2

#define _USE_MATH_DEFINES
#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
#include <vector>

double f(double x) {
    return 4.0 / (1.0 + x * x);
}

// Функции для численного интегрирования
double trap_pi(int n = 1000) {
    double h = 1.0 / n;
    double res = 0.5 * (f(0) + f(1));

    for (int i = 1; i < n; i++) {
        res += f(i * h);
    }

    return res * h;
}

double rect_pi(int n = 1000) {
    double h = 1.0 / n;
    double res = 0.0;

    for (int i = 0; i < n; i++) {
        res += f((i + 0.5) * h);
    }

    return res * h;
}

// Кубический сплайн
class CubicSpline {
public:
    vector<double> x, y, a, b, c, d;

    CubicSpline(const vector<double>& x_vals, const vector<double>& y_vals) : x(x_vals), y(y_vals) {
        int n = x.size();
        a = y;

        vector<double> h(n - 1), alpha(n - 1);
        for (int i = 0; i < n - 1; ++i) {
            h[i] = x[i + 1] - x[i];
            if (i > 0) {
                alpha[i] = (3.0 / h[i]) * (a[i + 1] - a[i]) - (3.0 / h[i - 1]) * (a[i] - a[i - 1]);
            }
        }

        vector<double> l(n), mu(n), z(n);
        l[0] = 1;
        mu[0] = z[0] = 0;

        for (int i = 1; i < n - 1; ++i) {
            l[i] = 2 * (x[i + 1] - x[i - 1]) - h[i - 1] * mu[i - 1];
            mu[i] = h[i] / l[i];
            z[i] = (alpha[i] - h[i - 1] * z[i - 1]) / l[i];
        }

        l[n - 1] = 1;
        z[n - 1] = 0;
        c.resize(n);
        c[n - 1] = 0;

        for (int j = n - 2; j >= 0; --j) {
            c[j] = z[j] - mu[j] * c[j + 1];
            b.push_back((a[j + 1] - a[j]) / h[j] - h[j] * (c[j + 1] + 2 * c[j]) / 3);
            d.push_back((c[j + 1] - c[j]) / (3 * h[j]));
        }
        reverse(b.begin(), b.end());
        reverse(d.begin(), d.end());
    }

    double interpolate(double xi) {
        int n = x.size();
        int i = n - 2;
        while (i >= 0 && xi < x[i]) --i;

        double dx = xi - x[i];
        return a[i] + b[i] * dx + c[i] * dx * dx + d[i] * dx * dx * dx;
    }
};

int main() {
    ofstream outfile("results.txt");

    if (!outfile) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    for (int i : {8, 32, 128}) {
        double t1 = trap_pi(i);
        double t2 = rect_pi(i);
        outfile << fixed << setprecision(6);
        outfile << "n = " << i << " - Rect: " << t1
            << " AE: " << abs(M_PI - t1)
            << "; Trap: " << t2
            << " AE: " << abs(M_PI - t2) << endl;
    }

    // Пример использования кубического сплайна
    vector<double> xs = { 0.0, 0.25, 0.5, 0.75, 1.0 };
    vector<double> ys;
    for (double x : xs) {
        ys.push_back(f(x));
    }

    CubicSpline spline(xs, ys);

    // Интерполяция и вывод значений
    for (double xi : {0.1, 0.2, 0.3, 0.4, 0.6, 0.8}) {
        double interpolated_value = spline.interpolate(xi);
        outfile << "Interpolated value at " << xi << ": " << interpolated_value << endl;
    }

    outfile.close();
    return 0;
}

//7.1.3

//#include <iostream>
//#include <iomanip>
//#include <cmath>
//#include <vector>
//#include <fstream>
//#include <functional>
//#define _USE_MATH_DEFINES
//#include <math.h>
//
//using namespace std;
//
//// Кусочная функция
//// f(x) = e^(x^2), 0 ≤ x ≤ 2
//// f(x) = 1/(4-sin(16πx)), 2 < x ≤ 4
//double f(double x) {
//    if (x <= 2.0) {
//        return exp(x * x);
//    }
//    else {
//        return 1.0 / (4.0 - sin(16.0 * M_PI * x));
//    }
//}
//
//// Адаптивный метод Симпсона
//double adaptive_simpson(double a, double b, double eps, int max_depth = 50) {
//    auto simpson = [](double a, double b, double fa, double fm, double fb) {
//        return (b - a) * (fa + 4.0 * fm + fb) / 6.0;
//        };
//
//    function<double(double, double, double, double, double, double, int)> adaptive_simpson_recursive;
//    adaptive_simpson_recursive = [&](double a, double b, double fa, double fm, double fb, double eps, int depth) {
//        double m = (a + b) / 2.0;
//        double fam = f((a + m) / 2.0);
//        double fmb = f((m + b) / 2.0);
//
//        double s1 = simpson(a, m, fa, fam, fm);
//        double s2 = simpson(m, b, fm, fmb, fb);
//        double s = s1 + s2;
//
//        if (depth <= 0) return s;
//
//        double s0 = simpson(a, b, fa, fm, fb);
//        if (fabs(s - s0) <= 15.0 * eps) return s + (s - s0) / 15.0;
//
//        return adaptive_simpson_recursive(a, m, fa, fam, fm, eps / 2, depth - 1) +
//            adaptive_simpson_recursive(m, b, fm, fmb, fb, eps / 2, depth - 1);
//        };
//
//    double m = (a + b) / 2.0;
//    return adaptive_simpson_recursive(a, b, f(a), f(m), f(b), eps, max_depth);
//}
//
//// Метод Гаусса (5 точек)
//double gauss5(double a, double b, const function<double(double)>& f) {
//    const int n = 5;
//    const double w[n] = { 0.2369268850561891,
//                        0.4786286704993665,
//                        0.5688888888888889,
//                        0.4786286704993665,
//                        0.2369268850561891 };
//    const double x[n] = { -0.9061798459386640,
//                        -0.5384693101056831,
//                         0.0000000000000000,
//                         0.5384693101056831,
//                         0.9061798459386640 };
//
//    double sum = 0.0;
//    for (int i = 0; i < n; i++) {
//        double t = x[i];
//        double xt = ((b - a) * t + (b + a)) / 2.0;
//        sum += w[i] * f(xt);
//    }
//    return sum * (b - a) / 2.0;
//}
//
//int main() {
//    // Открываем файл для записи результатов
//    ofstream out("integral_results.txt");
//    out << "method,value\n";
//
//    // Параметры
//    const double eps = 1e-10;
//    const int n_segments = 100;  // для построения графика
//
//    // 1. Вычисляем интеграл адаптивным методом Симпсона
//    double I1 = adaptive_simpson(0, 2, eps);  // первый участок
//    double I2 = adaptive_simpson(2, 4, eps);  // второй участок
//    double I_adaptive = I1 + I2;
//
//    // 2. Вычисляем интеграл методом Гаусса
//    auto f_lambda = [](double x) { return f(x); };
//    double I_gauss = gauss5(0, 2, f_lambda) + gauss5(2, 4, f_lambda);
//
//    // Выводим результаты
//    cout << fixed << setprecision(10);
//    cout << "Integral value:\n";
//    cout << "Adaptive Simpson: " << I_adaptive << endl;
//    cout << "Gauss (5 points): " << I_gauss << endl;
//    cout << "Difference: " << fabs(I_adaptive - I_gauss) << endl;
//
//    // Записываем результаты в файл
//    out << "adaptive_simpson," << I_adaptive << "\n";
//    out << "gauss5," << I_gauss << "\n";
//
//    // Записываем точки для построения графика
//    ofstream plot_data("function_points.txt");
//    plot_data << "x,f\n";
//
//    double h = 4.0 / n_segments;
//    for (int i = 0; i <= n_segments; i++) {
//        double x = i * h;
//        plot_data << x << " " << f(x) << "\n";
//    }
//
//    plot_data.close();
//    out.close();
//    return 0;
//}