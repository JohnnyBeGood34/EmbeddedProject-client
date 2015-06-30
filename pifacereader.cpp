#include "pifacereader.h"
#include "iostream"
using namespace std;
PifaceReader::PifaceReader()
{
}


void PifaceReader::readButtonPressed(int input,string& sequence_user,int& nbButtonPressed){

    switch(input){
    case 1:
        while(pfio_read_input()== 1);

        sequence_user.append("1");
        nbButtonPressed++;
        cout<< "bouton 1 pressé" <<endl;
    break;
    case 2 :
     while(pfio_read_input()== 2);
        sequence_user.append("2");

            nbButtonPressed++;
            cout<< "bouton 2 pressé" <<endl;
    break;

    case 4 :
     while(pfio_read_input()== 4);
       sequence_user.append("3");

            nbButtonPressed++;
            cout<< "bouton 3  pressé" <<endl;
    break;

    case 8 :
     while(pfio_read_input()== 8);
       sequence_user.append("4");

            nbButtonPressed++;
            cout<< "bouton 4 pressé" <<endl;
    break;
    default :
    //cout << "aucun bouton pressé"<<endl;
    break;
    }
}
