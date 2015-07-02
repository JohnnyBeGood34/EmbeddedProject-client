#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "tcpconnector.h"
#include "pfio.h"
#include <iostream>
#include "configfilemanager.h"
#include "pifacereader.h"
#include "doormansystem.h"
#include <fstream>

using namespace std;

#define CODES_LENGTH 4
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
#define PATH_PHOTO "/var/www/"

int main(int argc, char** argv)
{


    if (argc != 3) {
        printf("usage: %s <ip> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int serverPort = atoi(argv[2]);
    string serverAddress = argv[1];
    streampos begin,end;
    //    ifstream myfile ("/home/guest/Desktop/akinator.png", ios::binary);

    //    begin = myfile.tellg();
    //    myfile.seekg (0, ios::end);
    //    end = myfile.tellg();

    //    cout << "size is: " << (end-begin) << " bytes.\n";




    PifaceReader pifaceReader;
    char * configFile="/home/guest/Desktop/access.txt";
    ConfigFileReader fileReader(configFile);
    DoorManSystem doorMan(serverAddress,serverPort);
    int nb_btn_pressed=0;
    string sequence_user;
    map<string,string> codes= fileReader.getCodesAccess();



    pfio_init();

    while(true){

        usleep(100000);
        int input = pfio_read_input();

        //0 no button touched
        //1=> button 1 touched
        //2 => button 2 touched
        //4=> button 3 touched
        //8=> button 4 touched

        pifaceReader.readButtonPressed(input,sequence_user,nb_btn_pressed);


        if(nb_btn_pressed == CODES_LENGTH) {
            cout << "We got a sequence of  4 inputs " << endl;
            //Check if the sequence  is a user's one
            //Reset the  nb of times the buttons are pressed

            cout << " your sequence : "<< sequence_user << endl;

            system("sudo raspistill -o /var/www/test.jpg");
            doorMan.sendMessage("CODE|"+sequence_user);
            string messageReceived = doorMan.sendMessage("PHOTO|");

            if(messageReceived == "1"){

                char patterns[] = {0x1, 0xc, 0xd, 0x3, 0x1, 0x2, 0x4, 0x5, 0x6, 0x7};

                int i;
                for (i = 0; i < 10; i++)
                {
                    pfio_write_output(patterns[i]);
                    sleep(1);
                }
            }
            else cout << "access not granted"<< endl;

            //                           if(doorMan.getAGoodSequence(sequence_user,codes)){
            //                                //SEND A MESSAGE WITH THE SEQUENCE AND OK
            //
            //                           }
            //                           else {
            //                                //SEND A MESSAGE WITH THE SEQUENCE AND KO
            //                           }

            nb_btn_pressed=0;//Re-initialize the number of  times the buttons are pressed
            sequence_user="";

        }
    }

    pfio_deinit();

    exit(EXIT_SUCCESS);
}
