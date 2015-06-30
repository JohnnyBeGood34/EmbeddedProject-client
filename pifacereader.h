#ifndef PIFACEREADER_H
#define PIFACEREADER_H
#include "pfio.h"
#include <vector>
#include <string>

using namespace std;

class PifaceReader
{
public:
    PifaceReader();
    void readButtonPressed(int input,string& sequence_user,int& nbButtonPressed);
};

#endif // PIFACEREADER_H
