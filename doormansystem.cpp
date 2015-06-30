#include "doormansystem.h"
#include <iostream>

DoorManSystem::DoorManSystem()
{
}


bool DoorManSystem::getAGoodSequence(string &userSequence, map<string,string> &codesByPerson){

   return codesByPerson.find(userSequence) != codesByPerson.end();
}


void DoorManSystem::sendMessage(TCPStream* stream,string message){
    int len;

    char line[256];


    if (stream) {

        std::cout << "secure message sent"<< endl;
        stream->send(const_cast<char*>(message.c_str()), message.size());
        printf("sent - %s\n", message.c_str());

    }
}


string DoorManSystem::messageReceived(TCPStream *stream){
    int len;

    char line[256];

    if (stream) {

        len = stream->receive(line, sizeof(line));
        line[len] = 0;
        printf("received - %s\n", line);

    }

    return string(line);
}
