#ifndef USER_H
#define USER_H

#include <iostream>
#include "../Structures/AVLTree/AVLTree.h"
using namespace std;

class User
{
private:
	string nickname;
	string password;
	string name;
	AVLTree *assetAVL;

public:
	User(string nickname, string password, string name);
	~User();

	string getNickname();
	void setNickname(string nickname);

	string getPassword();
	void setPassword(string password);

	string getName();
	void setName(string name);

	AVLTree *getAssetAVL() const;
};

#endif // USER_H
