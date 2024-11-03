#include<iostream>
using namespace std;
int main()
{
	int n;
	_asm {
		mov EAX,n

	}

	/*int n;
	cin >> n;
	int n1=1;
	_asm {
		mov ECX,n
		mov BX,1
		mov EAX,1
		metka:mul BX
		add BX,1
		loop metka
		mov n,EAX
	}
	cout << n;*/

	/*int n;
	int shag;
	int first;
	cin >> n >> shag >> first;
	_asm {
		mov EAX,first
		mov EBX,shag
		add EBX,-1
		mov ECX,n
		metka:add EAX,EBX
		loop metka
		mov first,EAX
	}
	cout << first;*/

	//int n, f2 = 1;//объявление переменных
	//cin >> n;//количество слогаемых
	//int f1=1, f3=0;
	//n = n - 2;
	//_asm {//блок кода ассамблер
	//	mov EAX, 1
	//	mov EBX,f2
	//	mov EDX,0
	//	mov ECX,n//заполнение регистра переменными
	//	metka:add EDX, EAX//цикл
	//	add EDX,EBX//увеличиваем число которое будем складывать
	//	mov EAX,EBX
	//	mov EBX,EDX
	//	mov EDX,0
	//	loop metka
	//	mov f1,EBX//запись ответа 
	//}
	//cout << f1;//вывод
}