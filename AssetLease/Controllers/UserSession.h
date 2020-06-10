#ifndef USERSESSION_H
#define USERSESSION_H

#include "../Models/User.h"

class UserSession
{
private:
	static UserSession *instance;
	User *user;
	string department;
	string corporation;
	UserSession();

public:
	static UserSession *getInstance();
	~UserSession();

	User *getUser() const;
	void setUser(User *user);

	string getDepartment();
	void serDepartment(string department);

	string getCorporation();
	void setCorporation(string corporation);
};

#endif // USERSESSION_H