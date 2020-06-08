#include "AdministrativeMenu.h"
#include "../Structures/SparseMatrix/SparseMatrix.h"

AdministrativeMenu::AdministrativeMenu()
{
}

AdministrativeMenu::~AdministrativeMenu()
{
}

void AdministrativeMenu::interfaceDesign()
{
	SparseMatrix* sp;

	string option;
	string nickname;
	string name;
	string password;
	string department;
	string corporation;
	// SparseMatrix* sp = sp->getInstance();


	while (true)
	{
		system("CLS");
		cout << "----------------------------------------------------------------------" << endl;
		cout << "|                        MENU ADMINISTRADOR                          |" << endl;
		cout << "----------------------------------------------------------------------" << endl;
		cout << "----- 1. REGISTRAR USUARIO" << endl;
		cout << "----- 2. REPORTE MATRIZ DISPERSA" << endl;
		cout << "----- 3. REPORTE ACTIVOS DISPONIBLES DE UN DEPARTAMENTO" << endl;
		cout << "----- 4. REPORTE ACTIVOS DISPONIBLES DE UNA EMPRESA" << endl;
		cout << "----- 5. REPORTE TRANSACCIONES" << endl;
		cout << "----- 6. REPORTE ACTIVOS DE UN USUARIO" << endl;
		cout << "----- 7. REPORTE ACTIVOS RENTADOS POR UN USUARIO" << endl;
		cout << "----- 8. ORDENAR TRANSACCIONES" << endl;
		cout << "----- 9. CERRAR SESION" << endl;
		cout << ">> ";
		cin >> option;

		switch (option[0])
		{
		case '1':

			cout << "                         NOMBRE DE USUARIO" << endl;
			cout << ">> ";
			cin.ignore();
			getline(cin, nickname);
			cout << "                            CONTRASENIA" << endl;
			cout << ">> ";
			cin.ignore();
			getline(cin, password);
			cout << "                          NOMBRE COMPLETO" << endl;
			cout << ">> ";
			cin.ignore();
			getline(cin, name);
			cout << "                           DEPARTAMENTO" << endl;
			cout << ">> ";
			cin.ignore();
			getline(cin, department);
			cout << "                             EMPRESA" << endl;
			cout << ">> ";
			cin.ignore();
			getline(cin, corporation);
			sp->getInstance()->addNode(department,corporation, new User(nickname, password, name));
			break;
		case '2':
			sp->getInstance()->report();
			break;
		case '3':
			break;
		case '4':
			break;
		case '5':
			break;
		case '6':
			break;
		case '7':
			break;
		case '8':
			break;
		case '9':
			return;
		default:
			cout << ">> OPCION INCORRECTA" << endl;
			break;
		}
		system("pause");
	}
}
