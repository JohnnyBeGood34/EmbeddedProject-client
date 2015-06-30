#ifndef TCPCONNECTOR_H
#define TCPCONNECTOR_H



#if defined (WIN32)
    #include <winsock2.h>
    typedef int socklen_t;
#elif defined __linux__
    #include <sys/types.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <unistd.h>
#endif
#include "tcpstream.h"

/**
 * @brief The TCPConnector class provides the connect() method to actively establish
 * a connection with a server. It accepts the server port and a string containing
 * the server host name or IP address. If successful, a pointer to a TCPStream object is returned to the caller
 */
class TCPConnector
{
public:
    TCPStream* connect(const char* server, int port);
    //TCPStream* connect(const char* server, int port, int timeout);
private:
    int resolveHost(const char* host, struct in_addr* addr);
};

#endif // TCPCONNECTOR_H
