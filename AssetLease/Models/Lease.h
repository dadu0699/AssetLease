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
	bool state;

public:
	Lease(Asset *asset, User *user, string department, string corporation, string returnDate);
	~Lease();

	string getIdentifier();
	Asset *getAsset() const;
	User *getUser() const;
	string getDepartment();
	string getCorporation();
	string getLeaseDate();
	string getreturnDate();
	bool getState();
	void setState(bool state);
};

#endif // USER_H
