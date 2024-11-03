#include <iostream>
#include <fstream>
#include <windows.h>
#define PATH "D://seti/"
using namespace std;
struct Person
{
	string id;
	char name[25];  
	int a[4];
	int kol;
}B;
int answer;
long size_pred;
int main() 
{
	ifstream fR;
	ofstream fA;
	setlocale(LC_ALL, "rus");
	string nameR = "D://seti/REQUEST.txt";
	cout << "server is working" << endl;
	// начальные установки
	fR.open(nameR, ios::binary); //открытие файла REQUEST
	fR.seekg(0, ios::end);
	size_pred = fR.tellg(); //стартовая позиция сервера в файле REQUEST
	fR.close();

	// начало работы сервера
	while (true)
	{
		fR.open(nameR, ios::binary); //открытие файла REQUEST
		fR.seekg(0, ios::end); //переход в конец файла REQUEST
		// есть новые запросы от клиентов? 
		while (size_pred >= fR.tellg())
		{
			Sleep(100); fR.seekg(0, ios::end);
		}
		// получен новый запрос 
		fR.seekg(size_pred, ios::beg); //переход к началу полученного запроса
		fR.read((char*)&B, sizeof(B)); //считывание данных клиента
		size_pred = fR.tellg(); // на конец обработанных данных
		fR.close();
		// определение индекса массы	
		if (B.a[0] < 3 || B.a[1] < 3 || B.a[2] < 3 || B.a[3] < 3)answer = 0;
		else if (B.a[0] == 3 || B.a[1] == 3 || B.a[2] == 3 || B.a[3] == 3)answer = 1;
		else if (B.a[0] == 4 || B.a[1] == 4 || B.a[2] == 4 || B.a[3] == 4)answer = 2;
		else if (B.a[0] == 5 || B.a[1] == 5 || B.a[2] == 5 || B.a[3] == 5)answer = 3;
		// передача ответа клиенту
		string nameA = /*"D://seti/" + B.id + ".txt"*/"D://seti/ANSWER.txt";
		fA.open(nameA, ios::binary | ios::app); //открытие файла ANSWER
		if (!fA) cout << "File_answer_not_open " << endl;
		fA.write((char*)&B.id, sizeof(B.id));
		fA.write((char*)&answer, sizeof(answer)); //запись ответа клиенту
		fA.close();
	}// while
}