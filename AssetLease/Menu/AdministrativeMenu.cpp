#include "AdministrativeMenu.h"
#include "../Structures/SparseMatrix/SparseMatrix.h"
#include "../Structures/CircularDoublyLinkedList/CircularDoubleList.h"

AdministrativeMenu::AdministrativeMenu()
{
}

AdministrativeMenu::~AdministrativeMenu()
{
}

void AdministrativeMenu::interfaceDesign()
{
	SparseMatrix *sp;
	CircularDoubleList *cl;

	string option;
	string nickname;
	string name;
	string password;
	string department;
	string corporation;

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
		cout << "----- 8. ORDENAR TRANSACCIONES ASCENDENTE" << endl;
		cout << "----- 9. ORDENAR TRANSACCIONES DESCENDENTE" << endl;
		cout << "----- 0. CERRAR SESION" << endl;
		cout << ">> ";
		cin >> option;

		switch (option[0])
		{
		case '1':
			system("cls");
			cout << "                         NOMBRE DE USUARIO" << endl;
			cout << ">> ";
			cin.ignore();
			getline(cin, nickname);
			cout << "                            CONTRASENIA" << endl;
			cout << ">> ";
			getline(cin, password);
			cout << "                          NOMBRE COMPLETO" << endl;
			cout << ">> ";
			getline(cin, name);
			cout << "                           DEPARTAMENTO" << endl;
			cout << ">> ";
			getline(cin, department);
			cout << "                             EMPRESA" << endl;
			cout << ">> ";
			getline(cin, corporation);
			sp->getInstance()->addNode(department, corporation, new User(nickname, password, name));
			break;
		case '2':
			sp->getInstance()->report();
			break;
		case '3':
			system("cls");
			cout << "                           DEPARTAMENTO" << endl;
			cout << ">> ";
			cin.ignore();
			getline(cin, department);
			sp->getInstance()->printAssetsByDepartment(department);
			break;
		case '4':
			system("cls");
			cout << "                             EMPRESA" << endl;
			cout << ">> ";
			cin.ignore();
			getline(cin, corporation);
			sp->getInstance()->printAssetsByCorporation(corporation);
			break;
		case '5':
			cl->getInstance()->report();
			break;
		case '6':
			system("cls");
			cout << "                         NOMBRE DE USUARIO" << endl;
			cout << ">> ";
			cin.ignore();
			getline(cin, nickname);
			cout << "                           DEPARTAMENTO" << endl;
			cout << ">> ";
			getline(cin, department);
			cout << "                             EMPRESA" << endl;
			cout << ">> ";
			getline(cin, corporation);
			if (sp->getInstance()->getNode(department, corporation) != nullptr)
			{
				if (sp->getInstance()->getNode(department, corporation)->getUserList()->searchNode(nickname) != nullptr)
				{
					sp->getInstance()
						->getNode(department, corporation)
						->getUserList()
						->searchNode(nickname)
						->getUser()
						->getAssetAVL()
						->report(nickname, department, corporation);
				}
			}
			break;
		case '7':
			system("cls");
			cout << "                         NOMBRE DE USUARIO" << endl;
			cout << ">> ";
			cin.ignore();
			getline(cin, nickname);
			cout << "                           DEPARTAMENTO" << endl;
			cout << ">> ";
			getline(cin, department);
			cout << "                             EMPRESA" << endl;
			cout << ">> ";
			getline(cin, corporation);
			cl->getInstance()->report(department, corporation, nickname);
			break;
		case '8':
			cl->getInstance()->sortAscending();
			break;
		case '9':
			cl->getInstance()->sortDescending();
			break;
		case '0':
			return;
		default:
			cout << ">> OPCION INCORRECTA" << endl;
			break;
		}
		system("pause");
	}
}
