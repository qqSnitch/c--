//server 
#include <iostream> 
#include <winsock2.h> 
#include <Ws2tcpip.h> // Добавляем заголовочный файл для использования inet_ntop и INET_ADDRSTRLEN 
#pragma comment(lib,"ws2_32.lib") 
#pragma warning(disable: 4996) 
using namespace std;

struct Person
{
    string name;
    double grade[4];
};

int main()
{
    double ans;
    WSADATA wsa;
    cout << "Initialising Winsock...";
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
    {
        cout << "Failed. Error Code : " << WSAGetLastError();
        return 1;
    }
    cout << "Complete" << endl;

    cout << "Creating socket...";
    SOCKET ListenSock = socket(AF_INET, SOCK_DGRAM, 0);
    if (ListenSock == INVALID_SOCKET)
    {
        cout << "Failed.";
        return 1;
    }
    cout << "Complete" << endl;

    sockaddr_in serv;
    serv.sin_addr.s_addr = INADDR_ANY;
    serv.sin_family = AF_INET;
    serv.sin_port = htons(1234);

    bind(ListenSock, (sockaddr*)&serv, sizeof(serv));

    Person human;
    sockaddr_in from_serv;
    string ot;

    while (1)
    {
        char clientIp[INET_ADDRSTRLEN];
        int from_len = sizeof(from_serv);

        // Принятие данных от клиента 
        ot = recvfrom(ListenSock, (char*)&human, sizeof(human), 0, (sockaddr*)&from_serv, &from_len);

        // Вывод IP-адреса клиента 
        inet_ntop(AF_INET, &from_serv.sin_addr, clientIp, INET_ADDRSTRLEN);
        cout << "Client IP: " << clientIp << endl;

        cout << "Received data: Name: " << human.name << ", grade: " << human.grade[0] << "," << human.grade[1] << "," << human.grade[2] << "," << human.grade[3] << endl;
        ans = (human.grade[0] + human.grade[1] + human.grade[2] + human.grade[3]) / 4;
        cout << "Sr znach: " <<ans << endl;

        sendto(ListenSock, (char*)&ans, sizeof(ans), 0, (sockaddr*)&from_serv, from_len);
    }

    return 0;
}