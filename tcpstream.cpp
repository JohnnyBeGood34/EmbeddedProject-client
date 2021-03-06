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
#include <iostream>
using namespace std;
/**
 * @brief TCPStream::TCPStream The constructor stores the connected socket descriptor then converts the socket
 * information structure fields to a peer IP address string and peer TCP port.
 * These parameters can be inspected with calls to TCPStream::getPeerIP() and TCPStream::getPeerPort()
 */
TCPStream::TCPStream(int sd, struct sockaddr_in* address) : m_sd(sd) {
    char ip[50];
    inet_ntop(PF_INET, (struct in_addr*)&(address->sin_addr.s_addr),
              ip, sizeof(ip)-1);
    m_peerIP = ip;
    m_peerPort = ntohs(address->sin_port);
}

/**
 * @brief TCPStream::~TCPStream destructor, simply close connections
 */
TCPStream::~TCPStream()
{
    close(m_sd);
}

/**
 * @brief TCPStream::send returns write of bytes values
 * @param buffer
 * @param len
 * @return
 */
ssize_t  TCPStream::send(char* buffer, size_t len){
    cout << buffer << endl;
    return write(m_sd, buffer, len);
}

/**
 * @brief TCPStream::receive returns read of bytes values
 * @param buffer
 * @param len
 * @return
 */
ssize_t TCPStream::receive(char* buffer, size_t len){
    return read(m_sd, buffer, len);
}

/**
 * @brief TCPStream::getPeerIP return IP address information of the peer to which the network application is connected
 * @return
 */
string TCPStream::getPeerIP()
{
    return m_peerIP;
}

/**
 * @brief TCPStream::getPeerPort return Port information of the peer to which the network application is connected
 * @return
 */
int TCPStream::getPeerPort()
{
    return m_peerPort;
}
