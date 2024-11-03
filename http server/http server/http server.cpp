// www-server.cpp
//#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <string>
#include <WinSock2.h>
#include <WS2tcpip.h>
#pragma comment(lib, "Ws2_32.lib")
using std::cerr;

int main() {
    WSADATA wsaData;
    int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (result != 0) {
        cerr << "WSAStartup failed: " << result << "\n";
        return result;
    }
    struct addrinfo* addr = NULL;
    // структура для IP-адреса  сервера
    struct addrinfo hints;
    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    hints.ai_flags = AI_PASSIVE;
    // Инициализируем структуру addr 
    // HTTP-сервер на 8000-м порту localhost
    result = getaddrinfo("127.0.0.1", "8000", &hints, &addr);
    if (result != 0) {
        cerr << "getaddrinfo failed: " << result << "\n";
        WSACleanup(); // выгрузка библиотеки Ws2_32.dll
        return 1;
    }
    // Создание сокета
    int listen_socket =
        socket(addr->ai_family, addr->ai_socktype,
            addr->ai_protocol);
    if (listen_socket == INVALID_SOCKET) {
        cerr << "Error at socket: " << WSAGetLastError() << "\n";
        freeaddrinfo(addr);
        WSACleanup();
        return 1;
    }
    // Привязываем сокет к IP-адресу
    result = bind(listen_socket, addr->ai_addr, (int)addr->ai_addrlen);
    if (result == SOCKET_ERROR) {
        cerr << "bind failed with error: " << WSAGetLastError() << "\n";
        freeaddrinfo(addr);
        closesocket(listen_socket);
        WSACleanup();
        return 1;
    }
    // Инициализируем слушающий сокет
    if (listen(listen_socket, SOMAXCONN) == SOCKET_ERROR) {
        cerr << "listen failed with error: " << WSAGetLastError() << "\n";
        closesocket(listen_socket);
        WSACleanup();
        return 1;
    }
    const int max_client_buffer_size = 1024;
    char buf[max_client_buffer_size];
    int client_socket = INVALID_SOCKET;
    for (;;) // Принимаем входящие соединения
    {
        client_socket = accept(listen_socket, NULL, NULL);
        if (client_socket == INVALID_SOCKET) {
            cerr << "accept failed: " << WSAGetLastError() << "\n";
            closesocket(listen_socket);
            WSACleanup();
            return 1;
        }
        result = recv(client_socket, buf, max_client_buffer_size, 0);
        std::stringstream response;
        // сюда будет записываться ответ клиенту
        std::stringstream response_body; // тело ответа
        if (result == SOCKET_ERROR) {
            // ошибка получения данных
            cerr << "recv failed: " << result << "\n";
            closesocket(client_socket);
        }
        else if (result == 0) {
            // соединение закрыто клиентом
            cerr << "connection closed...\n";
        }
        else if (result > 0) {
            buf[result] = '\0';   // Данные успешно получены
            // формируем тело ответа (HTML)
            response_body << "<html>\n"
                << "<head>\n"
                << "<title>Test C++ HTTP Server</title>\n"
                << "<style>\n"
                << "body { font-family: Arial, sans-serif; }\n"
                << "h1 { color: blue; }\n"
                << "p { color: green; }\n"
                << "pre { background-color: lightgray; padding: 10px; }\n"
                << "</style>\n"
                << "</head>\n"
                << "<body>\n"
                << "<h1>Test page</h1>\n"
                << "<p>This is the body of the test page...</p>\n"
                << "<h2>Request headers</h2>\n"
                << "<pre>" << buf << "</pre>\n"
                << "<em><small>Test C++ Http Server</small></em>\n"
                << "<h2>About C++</h2>\n"
                << "<p>C++ is a general-purpose programming language that was developed as an extension of the C programming language. It provides features such as classes, objects, and inheritance, making it suitable for both low-level systems programming and high-level application development. C++ is known for its efficiency, performance, and flexibility, and it is widely used in various domains, including software development, game development, and embedded systems.</p>\n"
                << "</body>\n"
                << "</html>\n";

            // Формируем весь ответ вместе с заголовками
            response << "HTTP/1.1 200 OK\r\n"
                << "Version: HTTP/1.1\r\n"
                << "Content-Type: text/html; charset=utf-8\r\n"
                << "Content-Length: " << response_body.str().length()
                << "\r\n\r\n"
                << response_body.str();

            // Отправляем ответ клиенту 
            result = send(client_socket, response.str().c_str(),
                response.str().length(), 0);
            if (result == SOCKET_ERROR) {
                // произошла ошибка при отправке данных
                cerr << "send failed: " << WSAGetLastError() << "\n";
            }
            // Закрываем соединение к клиентом
            closesocket(client_socket);
        }
    } // конец for(;;)
    // Убираем за собой
    closesocket(listen_socket);
    freeaddrinfo(addr);
    WSACleanup();
    return 0;
}
