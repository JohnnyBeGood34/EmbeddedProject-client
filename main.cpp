#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "tcpconnector.h"
#include "pfio.h"
#include <iostream>
#include "configfilereader.h"
#include "pifacereader.h"
#include "doormansystem.h"

using namespace std;

#define CODES_LENGTH 4
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

int main(int argc, char** argv)
{


//    if (argc != 3) {
//        printf("usage: %s <port> <ip>\n", argv[0]);
//        exit(EXIT_FAILURE);
//    }


//    pfio_init();

    PifaceReader pifaceReader;
    char * configFile="/home/guest/Desktop/access.txt";
    ConfigFileReader fileReader(configFile);
    DoorManSystem doorMan;
    int nb_btn_pressed=0;
    string sequence_user;



        int port = 1234;
        string message="salut connard !";
        string address = argv[1];
        TCPConnector* connector = new TCPConnector();
        TCPStream* stream = connector->connect(address.c_str() , port);

        //doorMan.sendMessage(stream,"SDJA");

        //delete stream;
        //stream = connector->connect(address.c_str() , port);
        doorMan.sendMessage(stream,"CODE|1234");
        string receivedMessage = doorMan.messageReceived(stream);
        cout << "message reçu : "<<receivedMessage << endl;
        delete stream;
        stream = connector->connect(address.c_str() , port);
        doorMan.sendMessage(stream,"SIZE|1024");
        receivedMessage = doorMan.messageReceived(stream);
        cout << "message reçu : "<<receivedMessage << endl;
        delete stream;
        stream = connector->connect(address.c_str() , port);
        receivedMessage = doorMan.messageReceived(stream);
        doorMan.sendMessage(stream,"PHOTO|les octets de la tof");
        delete stream;

//    while(true){

//        int input = pfio_read_input();

//        //0 si aucune touche appuyée
//        //1=> touche 1 appuyée
//        //2 => touche 2 appuyée
//        //4=> touche 3 appuyée
//        //8=> touche 4 appuyée

//        pifaceReader.readButtonPressed(input,sequence_user,nb_btn_pressed);


//        if(nb_btn_pressed == CODES_LENGTH) {
//            cout << "We got a sequence of  4 inputs " << endl;
//            //Check if the sequence  is a user's one
//            //Reset the  nb of times the buttons are pressed
////           if(doorMan.getAGoodSequence(sequence_user,fileReader.getCodesAccess())){
////                //SEND A MESSAGE WITH THE SEQUENCE AND OK
////           }
////           else {
////                //SEND A MESSAGE WITH THE SEQUENCE AND KO
////           }
//                cout << " your sequence : "<< sequence_user << endl;

////           //Anyway take a picture and put it in the FTP folder
//                system("raspistill -o /home/usr/guest/Desktop/test.jpg");
//           nb_btn_pressed=0;//Re-initialize the number of  times the buttons are pressed
//        }
//    }

//    pfio_deinit();

    exit(EXIT_SUCCESS);
}
