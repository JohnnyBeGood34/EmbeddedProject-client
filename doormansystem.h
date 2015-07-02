#ifndef DOORMANSYSTEM_H
#define DOORMANSYSTEM_H
#include <string>
#include <map>
#include "tcpstream.h"

using namespace std;

class DoorManSystem
{
public:
    DoorManSystem(string serverAddress,int serverPort);
    bool getAGoodSequence(string& userSequence,map<string,string>& codesByPerson);
    string sendMessage(string message);
    string messageReceived(TCPStream* stream);
    void sendPhoto(char * imageBuffer,int size);
private :
    string _serverAddress;
    int _serverPort;
};

#endif // DOORMANSYSTEM_H
