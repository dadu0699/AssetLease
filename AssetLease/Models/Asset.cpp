#include "Asset.h"
#include "../Controllers/IDGenerator.h"

Asset::Asset(string name, string description)
{
	this->identifier = IDGenerator().getID();
	this->name = name;
	this->description = description;
}

Asset::~Asset()
{
}

string Asset::getIdentifier()
{
	return identifier;
}

void Asset::setIdentifier(string identifier)
{
	this->identifier = identifier;
}

string Asset::getName()
{
	return name;
}

void Asset::setName(string name)
{
	this->name = name;
}

string Asset::getDescription()
{
	return description;
}

void Asset::setDescription(string description)
{
	this->description = description;
}
