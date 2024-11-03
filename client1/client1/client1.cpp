#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

enum Mode
{
	WAITING_REQUEST = 0,
	WAITING_ANSWER = 1
};
struct Request // структура данных запроса клиента
{
	char name[25]; //имя
	int grade[4]; //оценка
	string file; // номер клиента
} A;

void main() {
	setlocale(LC_ALL, "rus");
	srand(time(NULL));//используем time(NULL) для инициализации генератора случайных чисел с помощью функции "srand()".
	Mode mode = WAITING_REQUEST;
	long fileSize = 0;//переменная для хранения размера файла
	int answer = 0;//переменная для хранения ответа от сервера

	string path = "D:/seti/";//"path" - строка, содержащая путь к папке "Information".
	string ServerFile = path + "request.bin";//указали путь до request.bin
	A.file = to_string(rand());//генерируем случайный номер клиента
	ofstream outFile;//выход поток
	ifstream inFile;//вход поток

	outFile.open(path + A.file + ".bin", ios::app | ios::binary);//создали файл клиента
	outFile.close();
	cout << A.file<<endl;
	while (true)//начало работы
	{
		if (mode == WAITING_REQUEST) // если в режиме ожидания, то отправляем запрос
		{
			cout << "Введите ФИО и 4 оценки студента:" << endl;
			cin >> A.name >> A.grade[0] >> A.grade[1] >> A.grade[2] >> A.grade[3]; // Ввод
			outFile.open(ServerFile, ios::app | ios::binary);//открыли файл сервера
			outFile.write((char*)&A, sizeof(A));//записываем в него структуру "A"
			outFile.close();
			mode = WAITING_ANSWER;//переходим в режим ожидания ответа от сервера
		}
		else // иначе ожидаем ответ
		{
			inFile.open(path + A.file + ".bin", ios::binary);//открываем файл
			inFile.seekg(0, ios::end);//перемещаем указатель чтения на позицию "fileSize"
			while (fileSize >= inFile.tellg())//проверка на наличие ответа
			{

				Sleep(100);
				fileSize = inFile.tellg();//получаем новый размер файла
			}
			//если есть ответ
			inFile.seekg(fileSize, ios::beg);//перемещаем указатель чтения на позицию "fileSize"
			inFile.read((char*)&answer, sizeof(answer));//читаем значение "answer" из файла
			fileSize = inFile.tellg();//обновили размер файла
			inFile.close();
			switch (answer)
			{
			case 1:
				cout << "У " << A.name << " имеется задолжность!" << endl;
				break;
			case 2:
				cout << "У " << A.name << " нет стипендии!" << endl;
				break;
			case 3:
				cout << "У " << A.name << " обычная стипендия!" << endl;
				break;
			case 4:
				cout << "У " << A.name << " повышенная стипендия!" << endl;
				break;
			default:
				cout << "Ошибка! Недопустимый ответ сервера: " << answer << endl;
				break;
			}
			cout << endl;
			mode = WAITING_REQUEST;
		}
		Sleep(100);
	}
}