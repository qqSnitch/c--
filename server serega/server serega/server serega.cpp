#include <iostream> 
#include <winsock2.h> 
#include <ws2tcpip.h> 
#include <sstream> 
#pragma comment(lib, "Ws2_32.lib") 

using namespace std;
#define DEFAULT_PORT "27015" 
#define STRSIZE 512 
#define LOGTAG "[Log-SERVER]" 
#define LOGTAG_RR "[Log-SERVER-ERR]" 
SOCKET INV_SOCK = INVALID_SOCKET;
#define INV_SOCK &INV_SOCK 
typedef addrinfo ADRESS_INFO;
typedef char buffer_c;

//#define USETCP 

struct Request
{
    char name[STRSIZE];
    int marks[4];
};

struct Answer
{
    char name[STRSIZE];
    int salary;
};

enum TRANSP_PROTO
{
    UDP,
    TCP
};

constexpr TRANSP_PROTO _get_transp_pr(void)
{
#ifdef USETCP 
    return TCP;
#else 
    return UDP;
#endif; 
}

constexpr TRANSP_PROTO CURRENT_TPROTO = _get_transp_pr();

[[nodiscard]]
constexpr int _iproto(void)
{
    return CURRENT_TPROTO == TCP ? IPPROTO_TCP : IPPROTO_UDP;
}

[[nodiscard]]
constexpr int _socktype(void)
{
    return CURRENT_TPROTO == TCP ? SOCK_STREAM : SOCK_DGRAM;
}

constexpr unsigned int I_PROTO = _iproto();
constexpr unsigned int I_SOCKTYPE = _socktype();

WSADATA init_server(void);
void init_adress(ADRESS_INFO&, ADRESS_INFO*&);
void try_create_socket(SOCKET*&, ADRESS_INFO*);
void try_bind_socket(SOCKET, ADRESS_INFO*);
void begin_socket_listen(SOCKET);
void try_create_client_socket(SOCKET*&, SOCKET);
void send_to_client_TCP(SOCKET*, const char*, int);
void send_to_client_UDP(SOCKET*, const char*, int, ADRESS_INFO*);
void shutdown_connect(SOCKET*);

inline bool _is_err(ostream& os)
{
    return &os == &cerr;
}

inline void _cnsllog(string s, ostream& os)
{
    os << (_is_err(os) ? LOGTAG_RR : LOGTAG) << s << endl;
}

inline void _CLEAN_UP_WSA()
{
    WSACleanup();
}

inline bool _is_valid_socket(SOCKET* sock)
{
    return (sock != nullptr && sock != INV_SOCK);
}

inline void _try_close_socket(SOCKET* sock)
{
    if (_is_valid_socket(sock)) {
        closesocket(*(sock));
    }
}

inline void _try_clean_adress(ADRESS_INFO* s)
{
    if (s != nullptr) {
        freeaddrinfo(s);
    }
}

inline int _getSalary(int* marks)
{
    int k = 0;
    for (int i = 0; i < 4; i++)
    {
        k += *(marks + i);
    }
    return (k / 4) * 750;
}

int startserver(void)
{
    unsigned int code = 0;
    SOCKET* LISTEN_SOCKET = nullptr;
    SOCKET* CLIENT_SOCKET = nullptr;
    ADRESS_INFO* result = nullptr;
    ADRESS_INFO s_info;
    buffer_c RECEIVE_BUFF[sizeof(Request)];
    buffer_c SEND_BUFF[sizeof(Answer)];

    const int sendbuffsz = sizeof(SEND_BUFF);
    const int reqbuffsz = sizeof(RECEIVE_BUFF);

    try
    {
        _cnsllog("Server init!", cout);
        WSADATA s_id = init_server();

        ZeroMemory(&s_info, sizeof(s_info));
        s_info.ai_family = AF_INET;
        s_info.ai_socktype = I_SOCKTYPE;
        s_info.ai_protocol = I_PROTO;

        _cnsllog("Init adress!", cout);
        init_adress(s_info, result);

        switch (CURRENT_TPROTO)
        {
        case TCP:
        {
            _cnsllog("Listen socket!", cout);
            try_create_socket(LISTEN_SOCKET, result);

            _cnsllog("Bind TCP!", cout);
            try_bind_socket(*LISTEN_SOCKET, result);

            _try_clean_adress(result);

            _cnsllog("Begin socket listener!", cout);
            begin_socket_listen(*LISTEN_SOCKET);

            _cnsllog("Client socket!", cout);
            try_create_client_socket(CLIENT_SOCKET, *LISTEN_SOCKET);
            _cnsllog("Continue...", cout);

            _try_close_socket(LISTEN_SOCKET);

            int res_id = 0;
            do
            {
                res_id = recv(*CLIENT_SOCKET, RECEIVE_BUFF, reqbuffsz, SD_RECEIVE);
                if (res_id > 0) {
                    Request req;
                    memcpy_s(reinterpret_cast<char*>(&req), sizeof(req), RECEIVE_BUFF, reqbuffsz);
                    string S(req.name);
                    _cnsllog(string("Bytes received: ").append(to_string(res_id)), cout);
                }
            }
        }
    }

        