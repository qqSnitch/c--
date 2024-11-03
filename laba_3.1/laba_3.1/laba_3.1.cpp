#include<iostream>
#include<ctime>
#include<fstream>
using namespace std;
short** img;
short** pic;
int n = 0,xmin=5,ymin=2;
void CreateImg(int x,int y)
{
	for (int i = 0; i < y; i++)
	{	
		for (int j = 0; j < x; j++)
		{
			if (i == j)
			{
				img[i][j] = 1;
				img[i][j + x / 2] = 1;
			}
			if (j==x-i-1)
			{
				img[i][x - i - 1] = 1;
				img[i][x - i - 1-x/2] = 1;
			}
		}
	}
}
void ClearImg(int x,int y)
{
	img = new short* [y];
	for (int i = 0; i < y; i++)
	{
		img[i] = new short[x];
		for (int j = 0; j < x; j++)
		{
			img[i][j] = 0;
		}
	}
}
void PrintImg(int x,int y)
{
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			cout << img[i][j]<<" ";
		}
		cout << endl;
	}
	cout << endl;
}
bool AddImgToPic(int x,int y,int posx,int posy)
{
	if (posx + x  > n)return false;
	if (posy + y  > n)return false;
	for (int i = posy; i < posy+y; i++)
	{
		for (int j = posx; j < posx+x; j++)
		{
			if (pic[i][j] == 1)
			{
				return false;
			}
		}
	}
	for (int i = posy; i < posy+y; i++)
	{
		for (int j = posx; j < posx+x; j++)
		{
			if(img[i-posy][j-posx]==1)
				pic[i][j] = img[i - posy][j - posx];
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
			cout << pic[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
int S()
{
	int counter = 0;
	for(int size=0;size<=8;size++)
	{
		counter += 7;
		bool f = true;
		int ysize = size + 2;
		int xsize= (ysize - 1) * 4 + 1;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				counter+=2;
				f = true;
				if (pic[i][j] == 1)
				{
					counter += 5;
					if (i + ysize > n||j+xsize>n)goto next;
					for (int i1 = i; i1 < i+ysize; i1++)
					{
						for (int j1 = j; j1 <j+ xsize; j1++)
						{
							
							counter++;
							if (i1 == j1)
							{
								if (pic[i1][j1] != 1)
								{
									counter++;
									f = false;
								}
								if (pic[i1][j1 + xsize / 2] != 1)
								{
									f = false;
									counter++;
								}
								counter += 4;
							}
							counter += 3;
							if (j1 == xsize - i1 - 1)
							{
								if (pic[i1][xsize - i1 - 1] != 1)
								{
									counter++;
									f = false;
								}
								if (pic[i1][xsize - i1 - 1 - xsize / 2] != 1)
								{
									counter++;
									f = false;
								}
								counter += 8;
							}
						}
					}
					if (f == true)
					{
						//cout << "HG: x=" << j + 1 << " y=" << i + 1 << endl << "LG: x=" << j + xsize << " y=" << i+ysize << endl << endl;
					}
					f = true; counter++;
				}
			}
		}
		next:;
	}
	return counter;
}
int main()
{
	ofstream f("f.txt");
	srand(time(0));
	int k = 0;
	for (n = 100; n < 1000; n += 100)
	{
		for (int g = 0; g < 100; g++)
		{
			int x, y, posx, posy;
			CreatePic();
			for (int t = 0; t < 10; t++)
			{
				y = rand() % (10 - 2 + 1) + 2;
				x = (y - 1) * 4 + 1;
				ClearImg(x, y);
				CreateImg(x, y);
				posy = rand() % (n);
				posx = rand() % (n);
				AddImgToPic(x, y, posx, posy);
			}
			k += S();
		}
		k /= 100;
		cout << "\nFor n= "<<n<<" k= " << k;
		f << "\nFor n= " << n << " k= " << k;
		k = 0;
	}
	
}
//#include <iostream>
//#include <vector>
//#include <time.h>
//
//using namespace std;
//
//short** picture;
//short** image;
//bool** px_map; // просто карта областей занятых изображениями
//short px0 = 0, px1 = 1;
//int n = 0;
//
//void printPic() {
//    for (int i = 0; i < n; i++) {
//        for (int k = 0; k < n; k++) {
//            if (picture[i][k] == px0) {
//                cout << " -";
//            }
//            else {
//                cout << " #";
//            }
//        }
//        cout << endl;
//    }
//}
//void createPic() {
//    picture = new short* [n];
//    px_map = new bool* [n];
//    for (int i = 0; i < n; i++) {
//        picture[i] = new short[n];
//        px_map[i] = new bool[n];
//        for (int k = 0; k < n; k++) {
//            picture[i][k] = px0;
//            px_map[i][k] = false;
//        }
//    }
//}
//void clearPic() {
//    for (int i = 0; i < n; i++) {
//        for (int k = 0; k < n; k++) {
//            picture[i][k] = px0;
//            px_map[i][k] = false;
//        }
//    }
//}
//void generateImg(int width, int height) { // создает изображение буквы Р
//    image = new short* [height];
//    for (int i = 0; i < height; i++) {
//        image[i] = new short[width];
//        for (int k = 0; k < width; k++) {
//            if (k == 0) {
//                image[i][k] = px1;
//            }
//            else if (k == width - 1 && i < height / 2) {
//                image[i][k] = px1;
//            }
//            else if (i == 0) {
//                image[i][k] = px1;
//            }
//            else if (i == height / 2) {
//                image[i][k] = px1;
//            }
//            else {
//                image[i][k] = px0;
//            }
//        }
//    }
//}
//
//bool F(int x, int y, int width, int height) { // ставит изображение в картинку
//    if (x + width - 1 > n) {
//        cout << "Ошибка! Выход за пределы картинки (x)" << endl;
//        return false;
//    }
//    if (y + height - 1 > n) {
//        cout << "Ошибка! Выход за пределы картинки (y)" << endl;
//        return false;
//    }
//    for (int i = y; i < y + height; i++) {
//        for (int k = x; k < x + width; k++) {
//            picture[i][k] = image[i - y][k - x];
//        }
//    }
//    return true;
//}
//
//void randomPic(int amount) { // Ф-ия размещает случайные изображения
//    int countPlaced = 0;
//    int rh, rw, rx, ry; // случайные параметры изображения
//    int minW, minH = 5;
//    int maxW, maxH = sqrt(n * n / (amount + sqrt(amount)));
//    bool** isEmptyPx = new bool* [n]; // карта занятых пикселей
//    bool canPlace;
//    for (int i = 0; i < n; i++)
//    {
//        isEmptyPx[i] = new bool[n];
//        for (int k = 0; k < n; k++)
//        {
//            isEmptyPx[i][k] = true;
//        }
//    }
//    while (countPlaced < amount)
//    {
//        canPlace = false;
//        rh = rand() % (maxH - minH) + minH;
//        minW = (rh + 1) / 2;
//        maxW = rh;
//        rw = rand() % (maxW - minW) + minW;
//        int tries = 0;
//        while (!canPlace) // пытаюсь найти место для размещения
//        {
//            if (tries > 100) // если долго не получается разместить изображение, то рандомим размер меньше
//            {
//                rh = rand() % (rh - minH) + minH;
//                minW = (rh + 1) / 2;
//                maxW = rh;
//                rw = rand() % (maxW - minW) + minW;
//                //cout << "Проблемы в размещении (pic" << (countPlaced + 1) << ")" << endl;
//                tries = 0;
//            }
//            tries++;
//            canPlace = true;
//            rx = rand() % (n - rw + 1);
//            ry = rand() % (n - rh + 1);
//            //cout << rx << "\t" << ry << endl;
//            for (int i = ry; i < ry + rh; i++)
//                for (int k = rx; k < rx + rw; k++)
//                    if (isEmptyPx[i][k] == false)
//                    {
//                        i = n;
//                        k = n;
//                        canPlace = false;
//                    }
//        }
//        // если найдено место для размещения, то продолжаем
//        generateImg(rw, rh);
//        F(rx, ry, rw, rh);
//        countPlaced++;
//        //cout << "pic" << (countPlaced) << ":\t" << rx << "\t" << ry << "\t" << rw << "\t" << rh << endl;
//        for (int i = ry - 1; i < n && i <= ry + rh; i++)
//        {
//            if (i < 0)
//                i++;
//            for (int k = rx - 1; k < n && k <= rx + rw; k++)
//            {
//                if (k < 0)
//                    k++;
//                isEmptyPx[i][k] = false;
//            }
//        }
//    }
//}
//
//int S() { // анализатор картинки
//    int imgCounter = 0;
//    int count = 0;
//    for (int i = 0; i < n; i++) {
//        for (int k = 0; k < n; k++) {
//            if (px_map[i][k] == false && picture[i][k] == px1) // нашел самый высокий пиксель
//            {
//                int highX = k;
//                int highY = i;
//                int downX = k;
//                int downY = i;
//                count += 4; // инициализация точек
//                for (bool isAreaClosed = false; !isAreaClosed; )
//                {
//                    // алгоритм делает 3 проверки вокруг #### области: (точки - это уже пройденные поисковиком пиксели, очевидно что среди них нет частей изображения)
//                    //  . .... .
//                    //  . #### 1
//                    //  2 #### 1
//                    //  2 3333 3
//                    // -----------------------------------------------------
//                    isAreaClosed = true;
//                    if (downX < n) // иду по правому краю области
//                        for (int x = downX + 1, y = highY; y < n && y <= downY; y++)
//                        {
//                            if (picture[y][x] == px1) {
//                                downX = x;
//                                count += 1;
//                                isAreaClosed = false;
//                                break;
//                            }
//                            count++; // сравнение
//                        }
//                    if (highX - 1 >= 0) // иду по левому краю области
//                        for (int x = highX - 1, y = highY + 1; y < n && y <= downY + 1; y++)
//                        {
//                            if (picture[y][x] == px1) {
//                                highX = x;
//                                if (downY < y)
//                                {
//                                    downY = y;
//                                    count++;
//                                }
//                                count += 2;
//                                isAreaClosed = false;
//                                break;
//                            }
//                            count++; // сравнение
//                        }
//                    if (downY + 1 < n) //иду по нижнему краю области
//                        for (int y = downY + 1, x = highX; x <= downX + 1; x++)
//                        {
//                            if (picture[y][x] == px1) {
//                                downY = y;
//                                if (downX < x)
//                                {
//                                    downX = x;
//                                    count++; // присвоение
//                                }
//                                count += 2;
//                                isAreaClosed = false;
//                                break;
//                            }
//                            count++; // сравнение
//                        }
//                    count += 3; // 3 сравнения
//                }
//                for (int y = highY; y <= downY; y++)
//                {
//                    for (int x = highX; x <= downX; x++)
//                    {
//                        px_map[y][x] = true;
//                        count++;
//                    }
//                }
//                imgCounter++;
//                //cout << endl << "Изображение " << imgCounter << ": " << endl;
//                //cout << "Верхняя правая точка: " << highX << "\t" << highY << endl;
//                //cout << "Нижняя левая точка:   " << downX << "\t" << downY << endl;
//            }
//            count += 2;
//        }
//    }
//    //cout << "Найдено изображений: " << imgCounter << endl;
//    //cout << endl << "Кол-во операций: " << count << endl << endl;
//    return count;
//}
//
//int main()
//{
//    setlocale(LC_ALL, "RUS");
//    srand(time(0));
//    cout << "Release" << endl;
//    long long sum;
//    int amount;
//    // Авто ввод и тесты
//    for (n = 100; n <= 1000; n += 100)
//    {
//        createPic();
//        cout << "Размер картинки: " << n << endl;
//        sum = 0;
//        amount = n * sqrt(n) / 200; // рандомлю кол-во изображений
//        cout << "кол-во изображений: " << amount << endl;
//        cout << "макс. высота изоб.: " << int(sqrt(n * n / (amount + sqrt(amount)))) << endl;
//        for (int k = 0; k < 100; k++)
//        {
//            clearPic();
//            randomPic(amount);
//            //printPic();
//            //cout << "Изображение " << (k + 1) << " готово" << endl << endl;
//            sum += S();
//        }
//        double mid = sum / (double)100;
//        cout << fixed << "Среднее кол-во операций: " << mid << endl;
//        cout << "-------------------------------------------------------" << endl;
//    }
//
//    // Ниже ручной ввод
//
//    /*cout << "Input size: ";
//    cin >> n;
//    createPic();
//    int x, y, height, width, imgKol, ImgCount = 0;
//    bool isAddedImg = false;
//    cout << "Введите кол-во изображений: ";
//    cin >> imgKol;
//    while (ImgCount < imgKol) {
//        cout << "Ввод изображения " << (ImgCount + 1) << ": " << endl;
//        cout << "Введите координаты x, y: ";
//        cin >> x >> y;
//        cout << "Введите ширину и высоту: ";
//        cin >> width >> height;
//        generateImg(width, height);
//        isAddedImg = F(x, y, width, height);
//        if (isAddedImg)
//        {
//            ImgCount++;
//        }
//    }
//    cout << "\nшаги:" << S() << endl;
//    printPic();*/
//
//    // 2n^2 + 
//
//    // Разные вводы и результаты:
//    //
//    // ---- 3 разных изображения на картинке 20х20
//    // 20 3 1 2 3 5 4 9 6 10 13 4 4 7
//    // ---> 1217
//    //
//    //  ---- 1 большое изображение на картинке 30х30
//    // 30 1 3 3 20 25
//    // ---> 2927
//    //
//    // ---- 5 разных изображений на картинке 50х50
//    // 50 5 1 2 3 5 3 19 14 20 10 0 6 10 24 7 10 20 40 40 6 9
//    // ---> 6918
//    //
//    // ---- 2 разных изображения на 20х20
//    // 20 2 1 2 3 5 10 4 5 8
//    // ---> 1061
//    // 20 2 2 3 3 5 12 7 5 8
//    // ---> 1061
//    // т.е. результат не зависит от расположения изображений
//
//    //   5 --> 50
//    //  10 --> 200
//    //  10 --> 200
//    //  20 --> 800
//    //  30 --> 1800
//    //  40 --> 3200
//    //  50 --> 5000
//    //  60 --> 7200
//    //  70 --> 9800
//    //  80 --> 12800
//    //  90 --> 16200
//    // 100 --> 20000
//    // 200 --> 80000
//    // 300 --> 180000
//    // 400 --> 320000
//    // 500 --> 500000
//    // 600 --> 720000
//    // 700 --> 980000
//    // 800 --> 1280000
//    // 900 --> 1620000
//    //1000 --> 2000000
//    //
//    /*  Размер картинки : 100 24339.250000
//        ------------------------------------------------------ -
//        Размер картинки : 200 99006.810000
//        ------------------------------------------------------ -
//        Размер картинки : 300 222852.810000
//        ------------------------------------------------------ -
//        Размер картинки : 400 398348.850000
//        ------------------------------------------------------ -
//        Размер картинки : 500 626188.410000
//        ------------------------------------------------------ -
//        Размер картинки : 600 902923.760000
//        ------------------------------------------------------ -
//        Размер картинки : 700 1227422.260000
//        ------------------------------------------------------ -
//        Размер картинки : 800 1602099.760000
//        ------------------------------------------------------ -
//        Размер картинки : 900 2041894.310000
//        ------------------------------------------------------ -
//        Размер картинки : 1000 2518413.890000*/
//}
