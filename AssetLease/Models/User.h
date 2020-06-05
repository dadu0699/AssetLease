#ifndef USER_H
#define USER_H

#include <iostream>
using namespace std;

class User
{
private:
	string nickname;
	string password;
	string name;
	// string assetAVL;

public:
	User(string nickname, string password, string name/*, string assetAVL*/);
	~User();

	string getNickname();
	void setNickname(string nickname);

	string getPassword();
	void setPassword(string password);

	string getName();
	void setName(string name);
};

#endif // USER_H
