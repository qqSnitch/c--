#include<iostream>
#include<ctime>
using namespace std;
int** a;
int* c;
int** b;
int counter=0;
void bublesort(int n)
{
	int temp;
	for (int i = n - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			counter += 2;
			if (c[j] > c[j + 1])
			{
				temp = c[j];
				c[j] = c[j + 1];
				c[j + 1] = temp;
				counter += 5;
			}
		}
	}
}
int main()
{
	srand(time(NULL));
	cout << "n/m";
	for (int i = 1; i <=30; i++)
		cout <<" " << i;
	cout << endl;
	for (int n = 1; n <= 3; n++)
	{
		cout << n<<"   ";
		for (int m = 1; m <= 30; m++)
		{
			for (int t = 0; t < 10; t++)
			{
				a = new int* [n];
				b = new int* [n];
				for (int i = 0; i < n; i++)
				{
					a[i] = new int[m];
					b[i] = new int[m];
					c = new int[n * m];
					for (int j = 0; j < m; j++)
					{
						a[i][j] = rand() % 100;
					}
				}
				int k = 0;
				for (int i = 0; i < n; i++)
				{
					for (int j = 0; j < m; j++)
					{
						c[k] = a[i][j];
						k++;
					}
				}
				k = 0;
				bublesort(n * m);
				for (int i = 0; i < n; i++)
				{
					for (int j = 0; j < m; j++)
					{
						b[i][j] = c[k];
						k++;
					}
				}
			}
			cout << counter/10 << " ";
			counter = 0;
			

		}
		cout << endl;
	}
}
