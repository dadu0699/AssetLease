#include "Lease.h"
#include "../Controllers/IDGenerator.h"

Lease::Lease(Asset *asset, User *user, string returnDate)
{
	this->identifier = IDGenerator().getID();
	this->asset = asset;
	this->user = user;
	this->returnDate = returnDate;
}

Lease::~Lease()
{
}

string Lease::getIdentifier()
{
	return identifier;
}

Asset* Lease::getAsset() const
{
	return asset;
}

User* Lease::getUser() const
{
	return user;
}

string Lease::getreturnDate()
{
	return returnDate;
}
