#ifndef TCPSTREAM_H
#define TCPSTREAM_H

#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string>

using namespace std;

/**
 * @brief The TCPStream class used to stream (send/receive) data over TCP/IP
 */
class TCPStream
{
    int     m_sd;
    string  m_peerIP;
    int     m_peerPort;

public:
    /**
     * frien, allow other classes or function to use functions and attributes from this class
     */
    friend class TCPAcceptor;
    friend class TCPConnector;

    ~TCPStream();
    /**
     * @brief send used to send data over TCP
     * @param buffer
     * @param len
     * @return
     */
    ssize_t send(char* buffer, size_t len);
    ssize_t receive(char* buffer, size_t len);
    /**
     * @brief getPeerIP return the IP address of peer
     * @return
     */
    string getPeerIP();
    /**
     * @brief getPeerPort return the port of peer
     * @return
     */
    int getPeerPort();

  private:
    /**
     * @brief TCPStream Constructor, private to avoid access from friends classes
     * @param sd
     * @param address
     */
    TCPStream(int sd, struct sockaddr_in* address);
    TCPStream();
    TCPStream(const TCPStream& stream);
};

#endif // TCPSTREAM_H
