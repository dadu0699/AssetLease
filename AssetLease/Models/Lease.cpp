#include "Lease.h"
#include "../Controllers/IDGenerator.h"

Lease::Lease(Asset *asset, User *user, string department, string corporation, string returnDate)
{
	this->identifier = IDGenerator().getID();
	this->asset = asset;
	this->user = user;
	this->department = department;
	this->state = true;
	this->corporation = corporation;
	this->returnDate = returnDate;
	this->leaseDate = "";
}

Lease::~Lease()
{
}

string Lease::getIdentifier()
{
	return identifier;
}

Asset *Lease::getAsset() const
{
	return asset;
}

User *Lease::getUser() const
{
	return user;
}

string Lease::getDepartment()
{
	return department;
}

string Lease::getCorporation()
{
	return corporation;
}

string Lease::getLeaseDate()
{
	return leaseDate;
}

string Lease::getreturnDate()
{
	return returnDate;
}

bool Lease::getState()
{
	return state;
}

void Lease::setState(bool state)
{
	this->state = state;
}
