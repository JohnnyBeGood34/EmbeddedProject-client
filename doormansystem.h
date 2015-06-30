#ifndef DOORMANSYSTEM_H
#define DOORMANSYSTEM_H
#include <string>
#include <map>
#include "tcpstream.h"

using namespace std;

class DoorManSystem
{
public:
    DoorManSystem();
    bool getAGoodSequence(string& userSequence,map<string,string>& codesByPerson);
    void sendMessage(TCPStream* stream,string message);
    string messageReceived(TCPStream* stream);
};

#endif // DOORMANSYSTEM_H
