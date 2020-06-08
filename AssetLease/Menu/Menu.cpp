#include "Menu.h"
#include "AdministrativeMenu.h"
#include "UserMenu.h"
#include "../Structures/SparseMatrix/SparseMatrix.h"

Menu::Menu()
{
}

Menu::~Menu()
{
}

void Menu::interfaceDesign()
{
	AdministrativeMenu* administrativeMenu = new AdministrativeMenu();
	UserMenu* userMenu = new UserMenu();
	SparseMatrix* sp;
	
	string nickname;
	string password;
	string department;
	string corporation;
	// SparseMatrix* sp = sp->getInstance();


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
		cin >> department;
		cout << "                             EMPRESA" << endl;
		cout << ">> ";
		cin >> corporation;

		if (nickname == "admin" && password == "admin" && department == "null" && corporation == "null")
		{
			administrativeMenu->interfaceDesign();
		}
		// Obtain node from the matrix through the department and corporation and verify if the user is found
		else if (false) 
		{
		}
		else
		{
			cout << ">> USER NOT FOUND" << endl;
		}
		system("pause");
	}
}
