#include "Menu.h"
#include "AdministrativeMenu.h"
#include "UserMenu.h"
#include "../Structures/SparseMatrix/SparseMatrix.h"
#include "../Controllers/UserSession.h"

Menu::Menu()
{
}

Menu::~Menu()
{
}

void Menu::interfaceDesign()
{
	AdministrativeMenu *administrativeMenu = new AdministrativeMenu();
	UserMenu *userMenu = new UserMenu();
	SparseMatrix *sp;
	UserSession *user;

	string nickname;
	string password;
	bool flag = false;
	string department;
	string corporation;

	while (true)
	{
		system("CLS");
		cout << "----------------------------------------------------------------------" << endl;
		cout << "|                          RENTA ACTIVOS                             |" << endl;
		cout << "----------------------------------------------------------------------" << endl;
		cout << "                         NOMBRE DE USUARIO" << endl;
		cout << ">> ";
		cin >> nickname;
		cout << "                           CONTRASENIA" << endl;
		cout << ">> ";
		cin >> password;
		cout << "                           DEPARTAMENTO" << endl;
		cout << ">> ";
		cin.ignore();
		getline(cin, department);
		cout << "                             EMPRESA" << endl;
		cout << ">> ";
		getline(cin, corporation);

		if (nickname == "admin" && password == "admin" && department == "null" && corporation == "null")
		{
			administrativeMenu->interfaceDesign();
		}
		// Obtain node from the matrix through the department and corporation and verify if the user is found
		else if (sp->getInstance()->getNode(department, corporation) != nullptr)
		{
			flag = true;
			if (sp->getInstance()->getNode(department, corporation)->getUserList()->searchNode(nickname, password) != nullptr)
			{
				user->getInstance()->setUser(sp->getInstance()
												 ->getNode(department, corporation)
												 ->getUserList()
												 ->searchNode(nickname, password)
												 ->getUser());
				user->getInstance()->setCorporation(corporation);
				user->getInstance()->serDepartment(department);
				userMenu->interfaceDesign();
			}
			else
			{
				cout << ">> USER NOT FOUND" << endl;
			}
		}
		else
		{
			cout << ">> USER NOT FOUND" << endl;
		}
		system("pause");
	}
}
