#ifndef TCPCONNECTOR_H
#define TCPCONNECTOR_H

#include <netinet/in.h>
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
