#include<iostream>
#include<set>
#include<string>
using namespace std;
set<char>num;
string a,b,b1,c;
int counter;
void rezol()
{
	int countV = 0, countX = 0; counter++;
	for (int i = 0; i < a.length(); i++)
	{
		counter++;
		if (isdigit(a[i]) != 0)
		{
			num.insert(a[i]);
		}
		if (a[i] == 'V')countV++; counter++;
	}
	cout << "Count different X: ";
	for (auto i : num)
	{
		countX++;
		counter++;
	}
	cout << countX << endl;
	cout << "Count of V: " << countV << endl;
	for (int i = 0; i < a.length(); i++)
	{
		counter++;
		if (a[i] == '(')
		{
			int k = i; counter++;
			while (a[k ] != ')')
			{
				b[k - i ] = a[k]; k++;
				counter += 4;
			}
		}
		counter++;
		if (a[i] == '&')
		{
			i++;
			int k = i;
			counter+=2;
			while (a[k - 1] != ')')
			{
				b1[k - i] = a[k]; k++;
				counter+=5;
			}
			break;
		}
	}
	bool f1 = false,f2=false; counter+=2;
	for (int i = 0; i < b.length(); i++)
	{
		counter++;
		if (isdigit(b[i]) != 0)
		{
			for (int j = 0; j < b1.length(); j++)
			{
				counter+=5;
				if (b1[j] == b[i] && b[i - 2] != '-'&&b1[j-2]!='-')
				{
					f1 = true;
					c += 'X';
					c += b[i];
					c += " V ";
					counter+=7;
				}
				counter+=5;
				if (b1[j] == b[i] && b[i - 2] == '-' && b1[j - 2] == '-')
				{
					f1 = true;
					c += '-';
					c += 'X';
					c += b[i];
					c += " V ";
					counter+=9;
				}
				counter += 5;
				if (b1[j] == b[i] && b[i - 2] == '-' && b1[j - 2] != '-')
				{
					f1 = true; counter++;
				}
				counter+=5;
				if (b1[j] == b[i] && b[i - 2] != '-' && b1[j - 2] == '-')
				{
					f1 = true; counter++;
				}
				counter++;
				if(b[i]!=b1[j]&&isdigit(b1[j]))
				{
					f2 = true; counter++;
				}
			}
			counter+=2;
			if (f2 == true && f1 == false)
			{
				if (b[i - 2] == '-')c += '-';
				c += 'X';
				c += b[i];
				c += " V ";
				counter+=10;
			}
			f2 = f1 = false; counter+=2;

		}
	}
	for (int j = 0; j < b1.length(); j++)
	{
		counter++;
		if(isdigit(b1[j])!=0)
		{
			for (int i = 0; i < b.length(); i++)
			{
				counter+=5;
				if (b[i] == b1[j] && b1[j - 2] != '-' && b[i - 2] != '-')
				{
					f1 = true; counter++;
				}
				counter+=5;
				if (b[i] == b1[j] && b1[j - 2] == '-' && b[i - 2] == '-')
				{
					f1 = true; counter++;
				}
				counter+=5;
				if (b[i] == b1[j] && b1[j - 2] != '-' && b[i - 2] == '-')
				{
					f1 = true; counter++;
				}
				counter+=5;
				if (b[i] == b1[j] && b1[j - 2] == '-' && b[i - 2] != '-')
				{
					f1 = true; counter++;
				}
				counter++;
				if (b1[j] != b[i] && isdigit(b[i]))
				{
					f2 = true; counter++;
				}
			}
			counter+=2;
			if (f2 == true&&f1==false)
			{
				if (b1[j - 2] == '-')c += '-';
				c += 'X';
				c += b1[j];
				c += " V ";
				counter+=10;
			}
			f2 = false;
			f1 = false;
			counter+=2;
		}
	}
	if (c[c.size() - 2] == 'V')
	{
		c.erase(c.end() - 2); 
		cout << c << "- Vipolnima"<<endl;
	}
	else
	{
		cout << "0 - Ne vipolnima" << endl;
	}
}
int main()
{
	cout << "KNF: ";
	cin >> a;
	b.resize(a.size());
	b1.resize(a.size());
	c.resize(a.size()*2);
	rezol();
	cout << "Kol: "<<counter;
}
//(x1)&(-x1) NO
//(x1)&(x2) Yes
// 
//(x1Vx2)&(x3) Yes
//(-x1V-x1)&(x1) NO
// 
//(x1V-x2)&(-x1Vx2) NO
//(X1V-X2)&(X1VX3) YES
//
//(X1V-X2)&(X1VX3V-X1) Yes
//(X1V-X2)&(-X1VX2V-X1) NO
// 
//(X1V-X2VX3)&(-X1VX2v-X3) YES
//(X1V-X2VX3)&(-X1VX2v-X3) NO

