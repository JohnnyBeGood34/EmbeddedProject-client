#include "doormansystem.h"
#include <iostream>
#include "tcpconnector.h"

DoorManSystem::DoorManSystem(string serverAddress,int serverPort):
    _serverAddress(serverAddress),_serverPort(serverPort)
{
}


bool DoorManSystem::getAGoodSequence(string &userSequence, map<string,string> &codesByPerson){

    return codesByPerson.find(userSequence) != codesByPerson.end();
}


string DoorManSystem::sendMessage(string message){

    TCPConnector* connector = new TCPConnector();
    TCPStream* stream = connector->connect(_serverAddress.c_str() , _serverPort);

    if (stream) {
        int len;

        char line[256];
        stream->send(const_cast<char*>(message.c_str()), message.size());
        printf("message envoyé - %s\n", message.c_str());
        len = stream->receive(line, sizeof(line));
        cout << "after receive"<<endl;
        line[len] = 0;
        printf("message reçu - %s\n", line);
        return string(line);
        delete stream;
    }

}


string DoorManSystem::messageReceived(TCPStream *stream){
    int len;

    char line[256];

    if (stream) {

        len = stream->receive(line, sizeof(line));
        line[len] = 0;
        printf("message reçu - %s\n", line);

    }

    return string(line);
}


void DoorManSystem::sendPhoto(char *imageBuffer,int size){
    std::cout << "SIZE : " << size << std::endl;
    TCPConnector* connector = new TCPConnector();
    TCPStream* stream = connector->connect(_serverAddress.c_str() , _serverPort);
}
