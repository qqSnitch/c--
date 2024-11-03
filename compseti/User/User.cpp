// User.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<fstream>
#include<Windows.h>
using namespace std;
struct Person
{
    char name[25];
    int height;
    int weight;
}A;

void main()
{
    setlocale(LC_ALL, "rus");
    const char* nameR = "REQUEST.bin";
    const char* nameA = "ANSWER.bin";
    ofstream f_REQ;
    ifstream f_ANS;
    long pred_size;
    int answer;
    while (true)
    {
        cout << "Введите запрос: Фамилия Рост Вес" << endl;
        cin >> A.name >> A.height >> A.weight;
        cout << A.name << A.height << A.weight;
        f_REQ.open(nameR, ios::app | ios::binary);
        f_REQ.write((char*)&A, sizeof(A));
        f_REQ.close();
        f_ANS.open(nameA, ios::binary);
        f_ANS.seekg(0, ios::end);
        pred_size = f_ANS.tellg();
        while (pred_size >= f_ANS.tellg())
        {
            Sleep(100);
            f_ANS.seekg(0, ios::end);
            f_ANS.seekg(pred_size, ios::beg);
            f_ANS.read((char*)&answer, sizeof(answer));
            f_ANS.close();
            switch (answer)
            {
            case 0: {cout << "Недостаток веса\n"; break; }
            case 1: {cout << "Норма веса\n"; break; }
            case 2: {cout << "Избыток веса\n"; break; }
            }
        }
    }
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
