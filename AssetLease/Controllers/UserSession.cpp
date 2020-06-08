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

void UserSession::setUser(User *user)
{
    this->user = user;
}
