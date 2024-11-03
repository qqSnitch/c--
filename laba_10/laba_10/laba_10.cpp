#include<iostream>
#include<vector>
#include<ctime>
#include<fstream>
using namespace std;
int k=0;
void bublesort(int n, vector<int> counter1, vector<int> counter2)
{
	int i, temp;
	for(int i=n-1;i>0;i--)
		for (int j = 0; j < i; j++)
		{
			k+=2;
			if (counter1[j] > counter1[j + 1])
			{
				temp = counter1[j];
				counter1[j] = counter2[j + 1];
				counter1[j + 1] = temp;
				k += 5;
			}
			k += 2;
			if (counter2[j] > counter2[j + 1])
			{
				temp = counter2[j];
				counter2[j] = counter2[j + 1];
				counter2[j + 1] = temp;
				k += 5;
			}
		}
}
void G2(int n, vector<vector<int>> g1, vector<vector<int>> g2)
{
	int r, l, x;
	for(int kol=0;kol<n-1;kol++)
	{
		vector<int>temp(n, 0);
		r = rand() % n;//номер строки\столбца на которую будем менять
		l = rand() % n;//номер строки\столбца которую будем менять местами
		g2.resize(n);
		for (int j = 0; j < n; j++)
		{
			x = g2[l][j];
			g2[l][j] = g2[r][j];
			g2[r][j] = x;
		}
		for (int j = 0; j < n; j++)
		{
			x = g2[j][l];
			g2[j][l] = g2[j][r];
			g2[j][r] = x;
		}
	}
}
bool check(int n, vector<vector<int>> g1, vector<vector<int>> g2)
{
	vector<int> counter1;
	vector<int> counter2;
	counter1.resize(n);
	counter2.resize(n);
	for (int i = 0; i < n; i++)
	{
		int count1 = 0,count2=0;
		for (int j = 0; j < n; j++)
		{
			if (g1[i][j] == 1) { count1++; k++; }
			k++;
			if (g2[i][j] == 1) { count2++; k++; }
			k++;
		}
		counter1[i] = count1; k++;
		counter2[i] = count2; k++;
		k++;
		if (count1 != count2)
		{
			return false;
		}
		bublesort(n, counter1, counter2);
		k++;
		if (counter1 != counter2)return false;
		count1 = 0; count2 = 0; k += 2;
	}
	return true;
}
int main()
{
	ofstream f("f.txt");
	srand(time(NULL));
	int n,sum;
	for (n = 1; n <= 20; n++) {
		sum = 0;
		for(int i=0;i<10;i++)
		{
			vector<vector<int>> g1(n, vector<int>(n, 0));
			vector<vector<int>> g2(n, vector<int>(n, 0));

			for (int i = 0; i < n; i++)
			{
				for (int j = i + 1; j < n; j++)
				{
					int r = rand() % 2;
					g1[i][j] = r;
					g1[j][i] = r;
				}
			}
			g2 = g1;
			G2(n, g1, g2);
			//if (check(n, g1, g2) == true)
			//	cout << k;
			check(n, g1, g2);
			
		}
		sum = k;
		k = 0;
		cout <<"Sum= " << sum/10 <<" For n= "<<n<<endl;
		f << "Sum= " << sum / 10 << " For n= " << n << endl;
	}
}	