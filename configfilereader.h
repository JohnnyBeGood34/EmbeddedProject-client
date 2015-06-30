#ifndef CONFIGFILEREADER_H
#define CONFIGFILEREADER_H
#include <string>
#include <vector>
#include <map>

using namespace std;

class ConfigFileReader
{
public:
    ConfigFileReader(char * pathToConfigFile);
    void readFile(char * pathToConfigFile);
     map<string,string> getCodesAccess();
private :
    char * _path;
    map<string,string> _codesAccess;
};

#endif // CONFIGFILEREADER_H
