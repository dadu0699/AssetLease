#include "IDGenerator.h"

IDGenerator::IDGenerator()
{
    alphanum = "0123456789abcdefghijklmnopqrstuvwxyz";
}

IDGenerator::~IDGenerator()
{
}

string IDGenerator::getID()
{
    string id = "";
    int length = 15;

    for (int i = 0; i < length; i++)
    {
        id += alphanum[rand() % alphanum.size()];
    }

    // cout << id << endl;
    return id;
}
