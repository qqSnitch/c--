#include<iostream>
#include<vector>
using namespace std;
int counter = 0;
bool reshetka(vector<vector<int>>& g) 
{
    vector<int>k;
    vector<int>m;
    int n = g.size();
    counter++;
    vector <int> degree;
    degree.resize(n);
    for (int i = 0; i < n; i++) {
        int kol = 0;
        counter++;
        for (int j = 0; j < n; j++)
        {
            counter++;
            if (g[i][j] == 1) {
                kol++;
                counter += 2;
            }
        }
        degree[i] = kol;
        counter++;
        if (degree[i] >= 5) {
            return false;
        }
        counter++;
    }

    int kol2 = 0;
    int kol3 = 0;
    int kol4 = 0;
    m.resize(n / 2 + 1);
    k.resize(n / 2 + 1);
    counter += 7;
    for (int i = 0; i < n; i++) {
        counter += 3;
        if (degree[i] == 2) {
            kol2++;
            counter++;
        }
        if (degree[i] == 3) {
            counter++;
            kol3++;
        }
        if (degree[i] == 4) {
            counter++;
            kol4++;
        }
    }
    counter += 2;
    if (kol2 == 4) {
        counter++;
        for (int i = 2; i <= n / 2 + 1; i++)
        {
            counter += 2;
            if (n % i == 0) {
                k[i] = i;
                m[i] = n / i;
                counter += 3;
            }
        }
        for (int i = 0; i <= n / 2 + 1; i++)
        {
            counter += 9;
            if ((kol4 == (k[i] - 2) * (m[i] - 2)) &&(kol3 == 2 * m[i] + 2 * k[i] - 8) ) {
                cout << "k = " << k[i] << " m = " << m[i] << endl;
                return true;
            }
        }
    }
    //исключение 
    int vol = 0;
    for (int i = 0; i < n; i++)
    {
        counter++;
        if (degree[i] == 1) {
            vol++;
            counter += 2;
        }
    }
    counter++;
    if (vol == 2) {
        for (int i = 0; i < n; i++) {
            counter += 2;
            if (degree[i] != 2 && degree[i] != 1) {
                return false;
            }
        }
        cout << "k = " << 1 << " m = " << n << endl;
        return true;
    }
    else
        return false;
}

int main() 
{
    vector<vector<int>>g;
    setlocale(LC_ALL ,"ru");
    for (int n = 8; n <= 10; n++)
    {
        g.resize(n);
        for (int i = 0; i < n; i++)
        {
            g[i].resize(n);
            for (int j = 0; j < n; j++)
            {
                g[i][j] = 0;
            }
            }
        /*for (int i = 0; i < n; i++)
        { 
            for(int j = 0; j < n; j++)
            {
                if (j > i)
                {
                    cin>>g[i][j];
                    g[j][i] = g[i][j];
                }
            }
        }*/
        g = { {0, 1, 0, 0, 0, 1, 0, 0, 0, 0},
{1, 0, 1, 0, 0, 0, 1, 0, 0, 0},
{0, 1, 0, 1, 0, 0, 0, 1, 0, 0},
{0, 0, 1, 0, 1, 0, 0, 0, 1, 0},
{0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 1, 0, 0, 0},
{0, 1, 0, 0, 0, 1, 0, 1, 0, 0},
{0, 0, 1, 0, 0, 0, 1, 0, 1, 0},
{0, 0, 0, 1, 0, 0, 0, 1, 0, 1},
{0, 0, 0, 0, 1, 0, 0, 0, 1, 0} };
        if (reshetka(g)==true)
        {
            cout << "Решётка" << endl;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    cout << g[i][j] << ' ';
                }
                cout << endl;
            }
        }
        else
        {
            cout << "Не решётка" << endl;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    cout << g[i][j] << " ";
                }
                cout << endl;
            }
        }
        cout << counter << endl;
        counter = 0;
    }
    
}


//{{0, 1, 0, 0, 0, 1, 0, 0, 0, 0},
//{1, 0, 1, 0, 0, 0, 1, 0, 0, 0},
//{0, 1, 0, 1, 0, 0, 0, 1, 0, 0},
//{0, 0, 1, 0, 1, 0, 0, 0, 1, 0},
//{0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
//{1, 0, 0, 0, 0, 0, 1, 0, 0, 0},
//{0, 1, 0, 0, 0, 1, 0, 1, 0, 0},
//{0, 0, 1, 0, 0, 0, 1, 0, 1, 0},
//{0, 0, 0, 1, 0, 0, 0, 1, 0, 1},
//{0, 0, 0, 0, 1, 0, 0, 0, 1, 0}}
// Решётка
//0 0 1 1 0 0 0 0
//0 0 0 1 0 1 1 0
//1 0 0 0 1 0 0 0
//1 1 0 0 1 0 0 0
//0 0 1 1 0 1 0 0
//0 1 0 0 1 0 0 1
//0 1 0 0 0 0 0 1
//0 0 0 0 0 1 1 0
//k = 2 m = 4
// 
//Не решётка
//0 1 0 0 0 1 0 1 1
//1 0 0 0 1 1 0 0 1
//0 0 0 0 0 0 1 1 1
//0 0 0 0 1 0 0 0 0
//0 1 0 1 0 0 1 1 0
//1 1 0 0 0 0 0 1 1
//0 0 1 0 1 0 0 0 1
//1 0 1 0 1 1 0 0 1
//1 1 1 0 0 1 1 1 0
//Не решётка
//0 1 0 1 1 1 0 0 0 0
//1 0 0 1 0 1 1 0 1 1
//0 0 0 1 0 1 0 1 1 1
//1 1 1 0 0 0 1 1 1 1
//1 0 0 0 0 0 0 0 1 0
//1 1 1 0 0 0 0 1 0 1
//0 1 0 1 0 0 0 1 1 0
//0 0 1 1 0 1 1 0 1 0
//0 1 1 1 1 0 1 1 0 1
//0 1 1 1 0 1 0 0 1 0
//Не решётка
//0 0 1 0 1 0 1 1
//0 0 0 1 1 0 0 0
//1 0 0 1 1 0 1 0
//0 1 1 0 1 1 1 1
//1 1 1 1 0 1 0 1
//0 0 0 1 1 0 0 0
//1 0 1 1 0 0 0 0
//1 0 0 1 1 0 0 0
//Не решётка
//0 1 0 0 0 0 0 0 0
//1 0 1 0 0 1 1 0 0
//0 1 0 0 1 1 1 0 1
//0 0 0 0 0 1 1 0 0
//0 0 1 0 0 1 0 1 0
//0 1 1 1 1 0 0 0 0
//0 1 1 1 0 0 0 1 1
//0 0 0 0 1 0 1 0 1
//0 0 1 0 0 0 1 1 0

