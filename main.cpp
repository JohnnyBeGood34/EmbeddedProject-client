#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "tcpconnector.h"
using namespace std;
int main(int argc, char** argv)
{
    if (argc != 3) {
        printf("usage: %s <port> <ip>\n", argv[0]);
        exit(1);
    }

    int len;
    string message;
    int port = 1234;
    char line[256];
    string address = "192.168.1.10";
    TCPConnector* connector = new TCPConnector();

    TCPStream* stream = connector->connect(address.c_str() , port);

    if (stream) {
        message = "Salut ça va?";
        stream->send(const_cast<char*>(message.c_str()), message.size());
        printf("sent - %s\n", message.c_str());
        len = stream->receive(line, sizeof(line));
        line[len] = 0;
        printf("received - %s\n", line);
        delete stream;
    }

    //stream = connector->connect(localhost.c_str() , 80);
    /*
    if (stream) {
        message = "Yoyoyo marcello?";
        stream->send(const_cast<char*>(message.c_str()), message.size());
        printf("sent - %s\n", message.c_str());
        len = stream->receive(line, sizeof(line));
        line[len] = 0;
        printf("received - %s\n", line);
        delete stream;
    }*/
    exit(0);
}
