#include "UserSession.h"

UserSession::UserSession()
{
    user = nullptr;
}

UserSession *UserSession::instance = nullptr;

UserSession *UserSession::getInstance()
{
    if (instance == nullptr)
    {
        instance = new UserSession();
    }
    return instance;
}

UserSession::~UserSession()
{
}

User *UserSession::getUser() const
{
    return user;
}

string UserSession::getDepartment()
{
    return department;
}

void UserSession::serDepartment(string department)
{
    this->department = department;
}

string UserSession::getCorporation()
{
    return corporation;
}

void UserSession::setCorporation(string corporation)
{
    this->corporation = corporation;
}

void UserSession::setUser(User *user)
{
    this->user = user;
}
