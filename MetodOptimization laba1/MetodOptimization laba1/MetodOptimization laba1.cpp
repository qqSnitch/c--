#include <iostream>
#include <fstream>
using namespace std;

double f(double x) {
    return x * x - 4 * x + 7;
}

double y_k(double a, double b, double e) {
    return (a + b - e) / 2;
}

double z_k(double a, double b, double e) {
    return (a + b + e) / 2;
}
double fibo(int n) {
    if (n == 0 || n==1) return 1;
    return fibo(n - 1) + fibo(n - 2);
}
void points(double a, double b, double x1,double x2,double x3) {
    ofstream func("points.txt");
    for (double i = a; i <= b; i += 0.5) {
        func << i << " " << f(i) << endl;
    }
    func <<endl<< x1 << " " << f(x1) << endl;
    func << x2 << " " << f(x2) << endl;
    func << x3 << " " << f(x3) << endl;
    func.close();
}

int main()
{
    double l = 0.5, e = 0.2, a = 0, b = 10, y = 0, z = 0, L, R = 0, N = 0;
    int k = 0;
    L = b - a;
    while (L > l) {
        y = y_k(a, b, e);
        z = z_k(a, b, e);
        cout << "y = " << y << ", z = " << z << endl;
        cout << "f(y) = " << f(y) << ", f(z) = " << f(z);
        if (f(y) <= f(z)) {
            b = z;
        }
        else {
            a = y;
        }
        cout << " [" << a << " ; " << b << "]" << endl;
        L = b - a;;
        N = 2 * (k + 1);
        cout << "N = " << N << endl;
        k++;
        cout << endl;
    }
    cout << "k=  " << k << endl;
    double x1 = (a + b) / 2;
    R = 1 / pow(2, N / 2);
    cout << "x = " << x1 << ", f(x) = " << f(x1) << ", R(N) = " << R<<" "<<N;


    cout <<"\n_________________________________________\n";


    a = 0; b = 10; y = 0; z = 0; R = 0; N = 0; L; k = 0;
    while (fibo(N) < (b-a)/l) {//Найти N
        N++;
    }
    y = a + (fibo(N - 2) / fibo(N)) * (b - a);
    z = a + (fibo(N - 1) / fibo(N)) * (b - a);
    while (k != N-2) {
        
        cout << "y = " << y << ", z = " << z << endl;
        cout << "f(y) = " << f(y) << ", f(z) = " << f(z);
        if (f(y) <= f(z)) {
            b = z;
            z = y;
            y = a + fibo(N - k - 3) / fibo(N - k - 1) * (b - a);
        }
        else {
            a = y;
            y = z;
            z = a + fibo(N - k - 2) / fibo(N - k - 1) * (b - a);
        }
        cout << " [" << a << " ; " << b <<"]"<< endl;
        L = k + 2;
        cout << "index of L = " << L <<" k= "<<k<< endl;
        k++;
        cout << endl;
    }
    cout << "y = " << y << ", z = " << z << endl;
    cout << "f(y) = " << f(y) << ", f(z) = " << f(z);
    z = y + e;
    if (f(y) <= f(z)) {
        b = z;
    }
    else {
        a = y;
    }
    L = k + 2;
    cout << " [" << a << " ; " << b << "]" << endl;
    cout << "index of L = " << L << " k= " << k << endl;
    double x2 = (a + b) / 2;
    R = 1 / fibo(N);
    cout << endl;
    cout << "x = " << x2 << ", f(x) = " << f(x2) << ", R(N) = " << R<<" "<<N;


    cout << "\n_________________________________________\n";


    a = 0; b = 10; y = 0; z = 0; R = 0; N = 0; L; k = 0;
    y = a+(3-sqrt(5))/2*(b-a);
    z = a+b-y;
    while ((b-a)>l) {

        cout << "y = " << y << ", z = " << z << endl;
        cout << "f(y) = " << f(y) << ", f(z) = " << f(z);
        if (f(y) <= f(z)) {
            b = z;
            z = y;
            y = a+b-y;
        }
        else {
            a = y;
            y = z;
            z = a+b-z;
        }
        cout << " [" << a << " ; " << b << "]" << endl;
        L = k + 2;
        cout << "index of L = " << L << " k= " << k << endl;
        k++;
        cout << endl;
    }
    double x3 = (a + b) / 2;
    R = pow(0.618, L - 1);
    cout << endl;
    cout << "x = " << x3 << ", f(x) = " << f(x3) << ", R(N) = " << R;


    points(0, 10, x1, x2, x3);
}
