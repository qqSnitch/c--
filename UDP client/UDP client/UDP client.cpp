#include <iostream>
#include<winsock2.h>
#pragma comment(lib,"ws2_32.lib")
#pragma warning(disable: 4996)
using namespace std;

struct Student
{
	string name;
	int a[4];
}B;

int main()
{
	WSADATA wsa;
	cout << ("Initialising Winsock...");
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		cout << ("Failed. Error Code : %d", WSAGetLastError());
		return 1;
	}
	cout << "Complete" << endl;

	sockaddr_in serv;
	serv.sin_addr.s_addr = inet_addr("127.0.0.1");
	serv.sin_family = AF_INET;
	serv.sin_port = htons(1234);
	int from_len = sizeof(serv);

	cout << "Creating socket...";
	SOCKET KlientSock = socket(AF_INET, SOCK_DGRAM, 0);
	if (KlientSock == INVALID_SOCKET)
	{
		cout << "Failed.";
		return 1;
	}
	cout << "Complete" << endl;

	int prov = 1;
	Student S;
	string to;
	int answer;
	cout << "Start connection to server...";
	if (connect(KlientSock, (sockaddr*)&serv, sizeof(serv)) != 0)
	{
		cout << "Failed.";
		return 1;
	}
	cout << "Complete!" << endl;
	while (prov == 1)
	{
		cout << "Insert the weight and height(in meters):" << endl;
		cin >> S.name >> S.a[0]>>S.a[1]>>S.a[2]>>S.a[3];
		send(KlientSock, (char*)&answer, sizeof(S), 0);
		to = recvfrom(KlientSock, (char*)&S, 64, 0, 0, 0);
		cout<<answer<<
		cout << endl << "Continue? 1-yes, 2-no" << endl;
		cin >> prov;
	}
	closesocket(KlientSock);
	return 0;
}
