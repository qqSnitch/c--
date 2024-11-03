#include<iostream>
#include<ctime>
#include<fstream>
using namespace std;
short** img;
short** pic;
int n = 0, xmin = 5, ymin = 2;
void CreateImg(int y,int mn)
{
	int y1=y*mn;
	int x = (y1 - 1) * 4 + 1;
	for (int i = 0; i < y1; i++)
	{
		for (int j = 0; j < x; j++)
		{
			if (i == j)
			{
				img[i][j] = 1;
				img[i][j + x / 2] = 1;
			}
			if (j == x - i - 1)
			{
				img[i][x - i - 1] = 1;
				img[i][x - i - 1 - x / 2] = 1;
			}
		}
	}
}
void ClearImg(int y)
{
	img = new short* [y];
	for (int i = 0; i < y; i++)
	{
		img[i] = new short[(y - 1) * 4 + 1 ];
		for (int j = 0; j < (y - 1) * 4 + 1; j++)
		{
			img[i][j] = 0;
		}
	}
}
void PrintImg(int y)
{
	int x = (y - 1) * 4 + 1;
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			cout << img[i][j];
		}
		cout << endl;
	}
	cout << endl;
}
bool AddImgToPic(int x, int y, int posx, int posy)
{
	int sizex = posx + x;
	int sizey = posy + y;
	if (posx + x > n)sizex=n-1;
	if (posy + y > n)sizey=n-1;
	/*for (int i = posy; i < posy + y; i++)
	{
		for (int j = posx; j < posx + x; j++)
		{
			if (pic[i][j] == 1)
			{
				return false;
			}
		}
	}*/
	for (int i = posy; i < sizey; i++)
	{
		for (int j = posx; j < sizex; j++)
		{
			if (i >= 0 && j >= 0) 
			{
				if (img[i - posy][j - posx] == 1)
					pic[i][j] = img[i - posy][j - posx];
			}
		}
	}
	return true;
}
void CreatePic()
{
	pic = new short* [n];
	for (int i = 0; i < n; i++)
	{
		pic[i] = new short[n];
		for (int j = 0; j < n; j++)
		{
			pic[i][j] = 0;
		}
	}
}
void PrintPic()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << pic[i][j];
		}
		cout << endl;
	}
	cout << endl;
}
void RaiseImg(int mode,int mn,int size)
{
	if (mode == 0)//левый верхний
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (pic[i][j] == 1 && pic[i + 1][j + 1] == 1 && pic[i + 1][j - 1] == 0 && pic[i - 1][j - 1] == 0)
				{
					CreatePic();
					int sizem = size * mn;
					ClearImg(sizem);
					CreateImg(sizem, 1);
					cout << "Size * " << mn << endl;
					for (int t = 0; t < mn; t++)
					{
						AddImgToPic((sizem - 1) * 4 + 1, sizem, j, i + t);
					}
					goto stop;
				}
			}
		}
	}
	if (mode == 1)//правый верхний
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (pic[i][j] == 1 && pic[i + 1][j + 1] == 0 && pic[i + 1][j - 1] == 1 && pic[i - 1][j + 1] == 0)
				{
					CreatePic();
					int sizem = size * mn;
					ClearImg(sizem);
					CreateImg(sizem, 1);
					cout << "Size * " << mn << endl;
					for (int t = 0; t < mn; t++)
					{
						AddImgToPic((sizem - 1) * 4 + 1, sizem, j - (sizem - 1) * 4, i+t) ;
					}
					goto stop;
				}
			}
		}
	}
	if (mode == 2)//левый нижний
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (pic[i][j] == 1 && pic[i + 1][j + 1] == 1 && pic[i + 1][j - 1] == 0 && pic[i - 1][j - 1] == 0)
				{
					CreatePic();
					int sizem = size * mn;
					ClearImg(sizem);
					CreateImg(sizem, 1);
					cout << "Size * " << mn << endl;
					for (int t = 0; t < mn; t++)
					{
						AddImgToPic((sizem - 1) * 4 + 1, sizem, j - (sizem - 1) * 4, i + t-sizem);
					}
					goto stop;
				}
			}
		}
	}
	if (mode == 3)//правый нижний
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (pic[i][j] == 1 && pic[i + 1][j + 1] == 0 && pic[i + 1][j - 1] == 1 && pic[i - 1][j + 1] == 0)
				{
					CreatePic();
					int sizem = size * mn;
					ClearImg(sizem);
					CreateImg(sizem, 1);
					cout << "Size * " << mn << endl;
					for (int t = 0; t < mn; t++)
					{
						AddImgToPic((sizem - 1) * 4 + 1, sizem, j - ((sizem - 1) * 4), i + t);
					}
					goto stop;
				}
			}
		}
	}
	if (mode == 4)//центр
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (pic[i][j] == 1 && pic[i + 1][j + 1] == 1 && pic[i + 1][j - 1] == 0 && pic[i - 1][j - 1] == 0)
				{
					CreatePic();
					int sizem = size * mn;
					ClearImg(sizem);
					CreateImg(sizem, 1);
					cout << "Size * " << mn << endl;
					for (int t = 0; t < mn; t++)
					{
						AddImgToPic((sizem - 1) * 4 + 1, sizem, j - ((sizem - 1) * 4) / 4, i + t - sizem / 2);
					}
					goto stop;
				}
			}
		}

	}
	stop:;
}
int main()
{
	srand(time(0));
	ofstream f("f.txt");
	n = 50;
	int k = 0,posx,posy,x,y,mn;
	mn = rand() % (4 - 2 + 1) + 2;
	y = rand() % (10 - 2 + 1) + 2;
	x = (y - 1) * 4 + 1;
	ClearImg(y);
	CreateImg(y,1);
	CreatePic();
	posy = rand() % (n);
	posx = rand() % (n);
	AddImgToPic(x, y,1, 1);//для mode=0
	//AddImgToPic(x, y, n-x-1,1);//mode=1
	//AddImgToPic(x, y, 1, n-y-1);//mode=2
	//AddImgToPic(x, y, n-x-1, n/2-y);//mode =3
	//AddImgToPic(x, y, n/4, n/2);//mode=4
	PrintPic();
	RaiseImg(0,mn,y);
	PrintPic();
}