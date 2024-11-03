#include &lt;bits/stdc++.h&gt;
using namespace std;
long long int bubbleSort(long long int m[], int n)
{
	int N = n;
	int k = 0;
	for (int i = 0; i & lt; n; i++)
	{
		for (int j = 0; j & lt; N - 1; j++)
		{
			if (m[j] & gt; m[j + 1]) { int temp = m[j]; m[j] = m[j + 1]; m[j + 1] = temp; k += 3; }
			k++;
		}
		N--;
		k++;
	}
	return k;
}
int main() {
	freopen(&quot; .. / input.txt & quot; , &quot; r & quot; , stdin);
	freopen(&quot; .. / output.txt & quot; , &quot; w & quot; , stdout);
	long long int res[40], I = 0;
	for (int n = 100; n & lt; = 1000; n += 100)
	{
		long long int m1[n], m2[n];
		for (int i = 0; i & lt; n; i++)
		{
			m1[i] = i;
			m2[i] = n - i;
		}
		res[I] = n; I++;
		res[I] = bubbleSort(m1, n); I++;
		res[I] = bubbleSort(m2, n); I += 2;
	}
	srand(time(0));
	long long int k;
	I = 3;
	for (int n = 100; n & lt; = 1000; n += 100)
	{
		k = 0;
		for (int i = 0; i & lt; 1000; i++)
		{
			long long int m[n];
			for (int j = 0; j & lt; n; j++)
			{
				m[j] = rand();
			}
			k += bubbleSort(m, n);
		}
		res[I] = k / 1000;
		I += 4;
	}

	for (int i = 0; i & lt; 40; i += 4)
	{
		cout& lt; &lt; &quot; n: &quot; &lt; &lt; res[i] & lt; &lt; &quot; min: &quot; &lt; &lt; res[i + 1] & lt; &lt; &quot; max: &quot; &lt; &lt; res[i + 2] & lt; &lt; &quot;
	mean: &quot; &lt; &lt; res[i + 3] & lt; &lt; endl;
	}
	return 0;
}