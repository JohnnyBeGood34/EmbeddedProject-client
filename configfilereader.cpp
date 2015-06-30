#include "configfilereader.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

ConfigFileReader::ConfigFileReader(char * pathToConfigFile):_path(pathToConfigFile)
{
    readFile(pathToConfigFile);
}

void ConfigFileReader::readFile(char * pathToConfigFile){
    fstream configFile;
    configFile.open(pathToConfigFile);
    string line;

    if(configFile.is_open()==false){
        cout << "can't open config file : " << pathToConfigFile << endl;
    }

    while(getline(configFile,line)){

        stringstream lineAccess(line);
        vector<string> temp;
        string buffer;
        while(lineAccess >> buffer){
            temp.push_back(buffer);
        }

        _codesAccess.insert(pair<string,string>(temp.at(0),temp.at(1)));
        //cout << " code : "<< temp.at(0) << "  personne : "<< temp.at(1)<<endl;
    }

    configFile.close();

}

map<string,string> ConfigFileReader::getCodesAccess(){
return _codesAccess;
}
