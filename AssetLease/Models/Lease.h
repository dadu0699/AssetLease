#ifndef LEASE_H
#define LEASE_H

#include <iostream>
#include <ctime>
#include "Asset.h"
#include "User.h"
using namespace std;

class Lease
{
private:
	string identifier;
	Asset *asset;
	User *user;
	string department;
	string corporation;
	string leaseDate;
	string returnDate;

public:
	Lease(Asset *asset, User *user, string department, string corporation, string returnDate);
	~Lease();

	string getIdentifier();
	Asset *getAsset() const;
	User *getUser() const;
	string getreturnDate();
};

#endif // USER_H
