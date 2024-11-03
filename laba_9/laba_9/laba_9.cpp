#include <iostream>
#include <string>
using namespace std;
string abc = "+-().,";
string num = "1234567890";
bool horner(string a)
{
	int countx=0,countc=0;
	if (a.length() == 0)return false;
	if (a.find('x') == string::npos)return false;
	for(int i=0;i<a.length();i++)
	{
		if (a[i] == '+')
			if (a[i + 1] == 'x')
			{
				if (a[i + 2] != '(' && i+2<a.length() )
				{
					return false;
				}
			}
			else return false;
		if (a[i] == '(')countx++;
		if (a[i] == ')')countc++;
	}
	if (countc != countx)return false;
	if(a[0]=='-')
	{
		for (int i = 1; i < a.length(); i++)
			if (isdigit(a[i]) == 0)
			{
				if (a[i] == '+')break;
				if (a[i] == '.' || a[i] == ',')
					i++;
				else return false;
			}
	}
	else
	{
		for (int i = 0; i < a.length(); i++)
			if (isdigit(a[i]) == 0)
			{
				if (a[i] == '+')break;
				if (a[i] == '.' || a[i] == ',')
					i++;
				else return false;
			}
	}
	return true;
}
int main()
{
	int f = 1;
	while(f==1)
	{
		string a;
		cin >> a;
		if (horner(a))cout << "It's Horner"<<endl;
		else cout << "It's not Horner"<<endl;
		cout << "Continue?  1-Yes  2-No\n";
		cin >> f;
	}
}