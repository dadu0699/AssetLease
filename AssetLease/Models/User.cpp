#include "User.h"

User::User(string nickname, string password, string name)
{
	this->nickname = nickname;
	this->password = password;
	this->name = name;
	this->assetAVL = new AVLTree();
}

User::~User()
{
}

string User::getNickname()
{
	return nickname;
}

void User::setNickname(string nickname)
{
	this->nickname = nickname;
}

string User::getPassword()
{
	return password;
}

void User::setPassword(string password)
{
	this->password = password;
}

string User::getName()
{
	return name;
}

void User::setName(string name)
{
	this->name = name;
}

AVLTree *User::getAssetAVL() const
{
	return assetAVL;
}
