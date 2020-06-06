#ifndef ASSET_H
#define ASSET_H

#include <iostream>
using namespace std;

class Asset
{
private:
	string identifier;
	string name;
	string description;

public:
	Asset(string name, string description);
	~Asset();

	string getIdentifier();
	void setIdentifier(string identifier);

	string getName();
	void setName(string name);

	string getDescription();
	void setDescription(string description);
};

#endif // ASSET_H
