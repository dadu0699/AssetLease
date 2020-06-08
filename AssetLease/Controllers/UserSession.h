#ifndef USERSESSION_H
#define USERSESSION_H

#include "../Models/User.h"

class UserSession
{
private:
	static UserSession *instance;
	User *user;
	UserSession();

public:
	static UserSession *getInstance();
	~UserSession();

	User *getUser() const;
	void setUser(User *user);
};

#endif // USERSESSION_H