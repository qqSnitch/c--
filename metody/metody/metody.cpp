#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int determ(vector<vector<double>>& a)
{
    double tmp = 0,d=0;
    int n = a.size();
    for (int k = 0; k < n - 1; k++) {
        for (int i = k + 1; i < n; i++) {
            tmp = -a[i][k] / a[k][k];
            for (int j = 0; j < n; j++) {
                a[i][j] += a[k][j] * tmp;
            }
        }
    }
    d = 1;
    for (int i = 0; i < n; i++) {
        d *= a[i][i];
    }
    return d;
}
int rangplus(vector<vector<double>>& matrix, vector<vector<double>>& submatrix, vector<double>& plus,int k)
{
    int n = matrix.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j == k)
            {
                submatrix[i][j] = plus[i];
            }
        }
    }
    if (determ(submatrix) == 0)
    {
        return 2;
    }
    else
    {
        return 3;
    }
}
int maxrang(vector<int> r)
{
    int n = r.size();
    int max = r[0];
    for (int i = 0; i < n; i++)
    {
        if (r[i] > max)
        {
            max = r[i];
        }
    }
    return max;
}
int main()
{
	int n = 3;
    vector<vector<double>> aplus1 (n, vector<double>(n));
    vector<vector<double>> aplus2 (n, vector<double>(n));
    vector<vector<double>> aplus3 (n, vector<double>(n));
	vector<vector<double>> a(n, vector<double>(n));
    vector<double> plus(3);
    vector<int> r(4);
	    cout << "Enter a: ";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}
    cout << "\nEnter a Plus: ";
    for (int j = 0; j < n; j++)
    {
        cin>>plus[j];
    }
    int rang;
    if (determ(a) == 0)
    {
        rang = 2;
    }
    else
    {
        rang = 3;
    }
    aplus1 = aplus2 = aplus3 = a;
    r[0] = rang;
    r[1] = rangplus(a, aplus1, plus, 0);
    r[2] = rangplus(a, aplus1, plus, 1);
    r[3] = rangplus(a, aplus1, plus, 2);
    int rang1 = maxrang(r);
    cout << "Rang: " << rang << endl;
    cout << "Rang Plus: " << rang1 << endl;
    if (rang == rang1) {
        cout << "sovmesno\n";
        if (rang < n) cout << "edinstv\n";
        else
            cout << "Mnogo\n";
    }

}



//0.1
//0.2
//0.3
//0.4
//0.5
//0.6
//0.7
//0.8
//0.9