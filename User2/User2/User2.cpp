#include <iostream>
#include <fstream>
#include <windows.h>
#include<string>
#include<ctime>
using namespace std;
// структура данных запроса клиента
struct Person
{
	string id;
	char name[25];  //имя
	int a [4];
	int kol;
} A;
void main() 
{
	srand(time(NULL));
	setlocale(LC_ALL, "rus");
	A.id = to_string(rand());
	cout << A.id << endl;
	const char* nameR = "D://seti/REQUEST.txt";
	const char* nameA = "D://seti/ANSWER.txt";//файл для запросов клиентов
	ofstream f_REQ;
	ifstream f_ANS;
	long pred_size;
	int answer;
	//string nameA = "D://seti/" + A.id + ".txt";
	f_ANS.open(nameA, ios::binary); //открытие файла ANSWER
	if (!f_ANS) cout << "File_answer_not_open "<<endl;
	while (true)
	{
		// передача данных от клиента серверу
		cout << "Введите запрос: имя, оценки(4) " << endl;
		cin  >> A.name >> A.a[0] >> A.a[1] >> A.a[2] >> A.a[3];
		for (int i = 0; i < 4; i++)
		{
			if (A.a[i] < 3)A.kol++;
		}
		f_REQ.open(nameR, ios::app | ios::binary); //открытие файла REQUEST 
		if (!f_REQ)cout << "File_not_open "<< endl;
		f_REQ.write((char*)&A, sizeof(A)); //запись запроса в файл REQUEST
		f_REQ.close();

		// поступил ответ от сервера?
		f_ANS.seekg(0, ios::end); //переход в конец файла ANSWER
		pred_size = f_ANS.tellg();
		while (pred_size >= f_ANS.tellg())
		{
			Sleep(100); // ждем и переходим в конец файла ANSWER
			f_ANS.seekg(0, ios::end);
		}
		// получение ответа от сервера	
		f_ANS.seekg(pred_size, ios::beg); // на начало нового ответа
		f_ANS.read((char*)&answer, sizeof(answer)); //считывание ответа
		f_ANS.close();

		// расшифровка ответа
		switch (answer)
		{
			case 0: {cout << "Имется задолженость=" << A.kol << "\n"; break; }
			case 1: {cout << "Получение стипендии невозможна \n"; break; }
			case 2: {cout << "Имеется стипендия \n"; break; }
			case 3: {cout << "Имеется повышенная стипендия \n"; }
		}
		
	} //while
}