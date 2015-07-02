#include <stdio.h>
#include <string.h>
#include <netdb.h>
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
#include <fcntl.h>
#include <errno.h>
#include "tcpconnector.h"

/**
 * @brief TCPConnector::connect() call takes a server host name or IP address
 * string and the server listening port as arguments.
 * The server struct sockaddr_in sin_family is set to PF_INET and
 * the sin_port is set to the TCP port on which the server is listening for connections.
 * @param server
 * @param port
 * @return
 */

TCPStream* TCPConnector::connect(const char* server, int port)
{
    struct sockaddr_in address;
    memset (&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    if (this->resolveHost(server, &(address.sin_addr)) != 0 ) {
        inet_pton(PF_INET, server, &(address.sin_addr));
    }

    int sd = socket(AF_INET, SOCK_STREAM, 0);

    if (::connect(sd, (struct sockaddr*)&address, sizeof(address)) != 0) {
        perror("connect() failed");
        return NULL;
    }

    return new TCPStream(sd, &address);
}


/**
 * @brief TCPConnector::resolveHostName used to resolve host name for DNS
 * @param hostname
 * @param addr
 * @return
 */
int TCPConnector::resolveHost(const char* hostname, struct in_addr* addr)
{
    struct addrinfo *res;

    int result = getaddrinfo (hostname, NULL, NULL, &res);
    if (result == 0) {
        memcpy(addr, &((struct sockaddr_in *) res->ai_addr)->sin_addr,
               sizeof(struct in_addr));
        freeaddrinfo(res);
    }
    return result;
}
