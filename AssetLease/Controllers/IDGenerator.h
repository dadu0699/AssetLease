#ifndef IDGENERATOR_H
#define IDGENERATOR_H

#include <iostream>
using namespace std;

class IDGenerator
{
private:
	string alphanum;

public:
	IDGenerator();
	~IDGenerator();

	string getID();
};

#endif // IDGENERATOR_H
