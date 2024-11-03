#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;
int k;

struct number
{
	int length;
	int* dig;
};

number sub(number a, number b)
{
	number c;
	c = a;

	for (int i = 0; i < b.length; ++i)
	{
		c.dig[i] -= b.dig[i];
		k += 2;
	}

	for (int i = 0; i < c.length - 1; ++i)
		if (c.dig[i] < 0)
		{
			int d = (c.dig[i] + 1) / 10 - 1;
			c.dig[i + 1] += d;
			c.dig[i] -= d * 10;
			k += 10;
		}
		else
			k++;
	return c;
}
number add(number a, number b)
{
	number l;
	l.length = a.length + 1;
	l.dig = new int[l.length];

	l.dig[a.length - 1] = a.dig[a.length - 1];
	l.dig[a.length] = 0;

	for (int i = 0; i < b.length; ++i)
	{
		l.dig[i] = a.dig[i] + b.dig[i];
		k += 2;
	}

	for (int i = 0; i < l.length - 1; ++i)
		if (l.dig[i] >= 10)
		{
			int c = l.dig[i] / 10;
			l.dig[i + 1] += c;
			l.dig[i] -= c * 10;
			k += 9;
		}
		else
			k++;

	return l;
}
number mult(number a, number b)
{
	number result;
	result.length = a.length + b.length;
	result.dig = new int[result.length];

	if (a.length < 16)
	{
		for (int i = 0; i < result.length; i++)
			result.dig[i] = 0;
		for (int i = 0; i < a.length; ++i)
			for (int j = 0; j < b.length; ++j)
			{
				result.dig[i + j] += a.dig[i] * b.dig[j];
				k += 3;
			}
	}
	else
	{

		number B2;
		B2.dig = b.dig;
		B2.length = (b.length + 1) / 2;
		number A2;
		A2.dig = a.dig;
		A2.length = (a.length + 1) / 2;

		number B1;
		B1.dig = b.dig + B2.length;
		B1.length = b.length / 2;
		number A1;
		A1.dig = a.dig + A2.length;
		A1.length = a.length / 2;

		number sumA = add(A2, A1);

		number sumB = add(B2, B1);

		number multsum = mult(sumA, sumB);
		k += 3;

		number A2B2 = mult(A2, B2);
		number A1B1 = mult(A1, B1);
		number sumA2B1A1B2 = sub(sub(multsum, A2B2), A1B1);
		k += 3;

		for (int i = 0; i < A2B2.length; ++i)
			result.dig[i] = A2B2.dig[i];

		for (int i = A2B2.length; i < A2B2.length + A1B1.length; ++i)
			result.dig[i] = A1B1.dig[i - A2B2.length];

		for (int i = 0; i < sumA2B1A1B2.length; ++i)
		{
			result.dig[A2.length + i] += sumA2B1A1B2.dig[i];
			k += 2;
		}

	}

	for (int i = 0; i < result.length - 1; ++i)
		if (result.dig[i] >= 10)
		{
			int c = result.dig[i] / 10;
			result.dig[i + 1] += c;
			result.dig[i] -= c * 10;
			k += 9;
		}
		else k++;

	return result;
}

void print(number a)
{
	for (int i = 0; i < a.length; i++)
		cout << a.dig[i] << " ";
	cout << endl;
}

number sh(number a)
{
	number g;
	g.length = a.length + 1;
	g.dig = new int[g.length];

	g.dig[0] = 0;
	for (int i = 0; i < a.length; ++i)
	{
		g.dig[i + 1] = a.dig[i];
		k += 2;
	}

	return g;
}
int main()
{
	ofstream file("answer.txt");
	srand(time(0));

	for (int n = 128; n <= 16384; n *= 2)
	{
		k = 0;
		number a;
		a.dig = new int[n];
		a.length = n;
		for (int i = 0; i < n - 1; i++)
			a.dig[i] = rand() % 10;
		a.dig[n - 1] = rand() % 9 + 1;

		number b;
		b.dig = new int[n];
		b.length = n;
		for (int i = 0; i < n - 1; i++)
			b.dig[i] = rand() % 10;
		b.dig[n - 1] = rand() % 9 + 1;
		mult(a, b);

		file << n << " " << k << "\n";
	}

	return 0;
}
