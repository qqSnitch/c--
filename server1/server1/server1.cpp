#include <iostream>
#include <fstream>
#include <windows.h>
#include <vector>
using namespace std;

struct Request // структура данных запроса клиента
{
	char name[25]; //имя
	int grade[4]; //оценка
	string file;
} B;

int answer;// храненит ответ сервера
long size_pred;//храненит текущую позицию сервера в файле запросов


int Stipendia()//определяет стипендию в зависимости от оценок
{
	for (int i = 0; i < 5; i++)
	{
		if (B.grade[i] == 2)//оценка=2
		{
			return 1;
		}
	}
	for (int i = 0; i < 5; i++)
	{
		if (B.grade[i] == 3)//оценка 3
		{

			return 2;
		}
	}
	for (int i = 0; i < 5; i++)
	{
		if (B.grade[i] == 4)//оценка 4
		{

			return 3;
		}
	}
	for (int i = 0; i < 5; i++)
	{
		if (B.grade[i] == 5)//оценка 5
		{
			return 4;
		}
	}
}

int main() {
	setlocale(LC_ALL, "rus");

	long size_of_request;// храненит размер файла запросов

	ofstream out_of_request;//выходной поток
	ofstream outClient;
	ifstream in_request;//входной поток

	string path = "D:/seti/";
	string inFile = path + "request.bin";//содержит полный путь к файлу request.bin


	out_of_request.open(inFile, ios::binary | ios::app); // если нет файла request, то мы его создадим
	out_of_request.close();

	in_request.open(inFile, ios::binary); //открыли файл request и запомнили его размер
	in_request.seekg(0, ios::end);//устанавливаем файловый указатель в конец файла
	size_of_request = in_request.tellg();
	in_request.close();
	while (true) // начало работы сервера
	{ // проверка наличия новых клиентов
		in_request.open(inFile, ios::binary); //открытие файла request.bin
		in_request.seekg(0, ios::end);//устанавливаем файловый указатель в конец файла
		if (size_of_request < in_request.tellg()) // Сравнение размера файла запросов с текущей позицией файла tellg().
			//Если размер меньше, значит найден новый клиент.
		{
			in_request.seekg(size_of_request, ios::beg);//устанавливаем файловый указатель в начало файла
			in_request.read((char*)&B, sizeof(B));//Чтение имени нового клиента из файла
			outClient.open(path + B.file + ".bin", ios::app | ios::binary);//открыли клиента
			cout << path + B.file + ".bin" << endl;//путь до файла клиента
			answer = Stipendia();//Вызов функции Stipendia() для определения стипендии.
			outClient.write((char*)&answer, sizeof(answer));//Запись ответа в файл с помощью функции write().
			outClient.close();
			cout << "Ответ отправлен ";
			in_request.seekg(0, ios::end);//устанавливаем файловый указатель в конец файла
			size_of_request = in_request.tellg();// сохраняем новый размер файла
			cout << "Размер файла запросов: " << size_of_request << endl;//сколько байт находится в файле request.bin
		}
		in_request.close();
		Sleep(100);//Ожидание в течение 100 миллисекунд
	}
}