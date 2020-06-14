#include "UserMenu.h"
#include "../Controllers/UserSession.h"
#include "../Structures/SparseMatrix/SparseMatrix.h"
#include "../Structures/CircularDoublyLinkedList/CircularDoubleList.h"
#include "../Models/Lease.h"

UserMenu::UserMenu()
{
}

UserMenu::~UserMenu()
{
}

void UserMenu::interfaceDesign()
{
	UserSession *us;
	SparseMatrix *sp;
	AVLTreeNode *asset;
	CircularDoubleList *dbList;

	string option;
	string name;
	string department;
	string corporation;
	string description;
	DoubleNode *dbN;
	SparseMatrixNode *spN;

	while (true)
	{
		system("CLS");
		cout << "----------------------------------------------------------------------" << endl;
		cout << "|                           MENU USUARIO                             |" << endl;
		cout << "----------------------------------------------------------------------" << endl;
		cout << "----- 1. AGREGAR ACTIVO" << endl;
		cout << "----- 2. ELIMINAR ACTIVO" << endl;
		cout << "----- 3. MODIFICAR ACTIVO" << endl;
		cout << "----- 4. RENTAR ACTIVO" << endl;
		cout << "----- 5. DEVOLVER ACTIVO" << endl;
		cout << "----- 6. ACTIVOS RENTADOS" << endl;
		cout << "----- 7. MIS ACTIVOS RENTADOS" << endl;
		cout << "----- 8. CERRAR SESION" << endl;
		cout << ">> ";
		cin >> option;

		switch (option[0])
		{
		case '1':
			system("CLS");
			cout << "----------------------------------------------------------------------" << endl;
			cout << "|                         AGREGAR ACTIVO                             |" << endl;
			cout << "----------------------------------------------------------------------" << endl;
			cout << "                             NOMBRE" << endl;
			cout << ">> ";
			cin.ignore();
			getline(cin, name);
			cout << "                           DESCRIPCION" << endl;
			cout << ">> ";
			getline(cin, description);
			us->getInstance()->getUser()->getAssetAVL()->insert(new Asset(name, description));
			system("pause");
			break;
		case '2':
			system("CLS");
			cout << "----------------------------------------------------------------------" << endl;
			cout << "|                        ELIMINAR ACTIVO                             |" << endl;
			cout << "----------------------------------------------------------------------" << endl;
			us->getInstance()->getUser()->getAssetAVL()->inOrder();
			cout << "                                ID" << endl;
			cout << ">> ";
			cin.ignore();
			getline(cin, name);
			asset = us->getInstance()->getUser()->getAssetAVL()->search(name);
			if (asset != nullptr)
			{
				cout << ">> ID = " << asset->getAsset()->getIdentifier() << "; "
					 << "Nombre = " << asset->getAsset()->getName() << "; "
					 << "Descripcion = " << asset->getAsset()->getDescription() << "; "
					 << endl;
				us->getInstance()->getUser()->getAssetAVL()->deleteNode(name);
			}
			system("pause");
			break;
		case '3':
			system("CLS");
			cout << "----------------------------------------------------------------------" << endl;
			cout << "|                         MODIFICAR ACTIVO                           |" << endl;
			cout << "----------------------------------------------------------------------" << endl;
			us->getInstance()->getUser()->getAssetAVL()->inOrder();
			cout << "                                ID" << endl;
			cout << ">> ";
			cin.ignore();
			getline(cin, name);
			asset = us->getInstance()->getUser()->getAssetAVL()->search(name);
			if (asset != nullptr)
			{
				cout << ">> ID = " << asset->getAsset()->getIdentifier() << "; "
					 << "Nombre = " << asset->getAsset()->getName() << "; "
					 << "Descripcion = " << asset->getAsset()->getDescription() << "; "
					 << endl;
				cout << "                     NUEVA DESCRIPCION" << endl;
				cout << ">> ";
				getline(cin, description);
				asset->getAsset()->setDescription(description);
				cout << ">> ID = " << asset->getAsset()->getIdentifier() << "; "
					 << "Nombre = " << asset->getAsset()->getName() << "; "
					 << "Descripcion = " << asset->getAsset()->getDescription() << "; "
					 << endl;
			}
			system("pause");
			break;
		case '4':
			system("CLS");
			cout << "----------------------------------------------------------------------" << endl;
			cout << "|                         CATALOGO ACTIVOS                           |" << endl;
			cout << "----------------------------------------------------------------------" << endl;
			sp->getInstance()->printCatalogue(us->getInstance()->getUser()->getNickname(),
											  us->getInstance()->getUser()->getPassword());
			cout << "----------------------------------------------------------------------" << endl;
			cout << "|                          RENTAR ACTIVO                             |" << endl;
			cout << "----------------------------------------------------------------------" << endl;
			cout << "                                ID" << endl;
			cout << ">> ";
			cin.ignore();
			getline(cin, name);
			cout << "                           DEPARTAMENTO" << endl;
			cout << ">> ";
			getline(cin, department);
			cout << "                             EMPRESA" << endl;
			cout << ">> ";
			getline(cin, corporation);
			cout << "                        TIEMPO PARA RENTAR" << endl;
			cout << ">> ";
			getline(cin, description);
			spN = sp->getInstance()->getNode(department, corporation);
			if (spN != nullptr)
			{
				dbN = spN->getUserList()->getFirstNode();
				while (dbN != nullptr)
				{
					asset = dbN->getUser()->getAssetAVL()->search(name);
					if (asset != nullptr)
					{
						asset->getAsset()->setLease(true);
						dbList->getInstance()->addNode(new Lease(asset->getAsset(),
																 us->getInstance()->getUser(), us->getInstance()->getDepartment(),
																 us->getInstance()->getCorporation(), description));
						cout << ">> Transasccion realizada";
					}
					dbN = dbN->getNextNode();
				}
				cout << endl;
			}
			system("pause");
			break;
		case '5':
			system("CLS");
			cout << "----------------------------------------------------------------------" << endl;
			cout << "|                          DEVOLVER ACTIVO                           |" << endl;
			cout << "----------------------------------------------------------------------" << endl;
			dbList->getInstance()->readStartNodes(us->getInstance()->getUser());
			cout << "                                ID" << endl;
			cout << ">> ";
			cin.ignore();
			getline(cin, name);
			if (dbList->getInstance()->searchNode(name))
			{
				dbList->getInstance()->deleteSpecificNode(name);
			}
			system("pause");
			break;
		case '6':
			system("CLS");
			cout << "----------------------------------------------------------------------" << endl;
			cout << "|                          ACTIVOS RENTADOS                          |" << endl;
			cout << "----------------------------------------------------------------------" << endl;
			dbList->getInstance()->readStartNodes(us->getInstance()->getUser());
			system("pause");
			break;
		case '7':
			system("CLS");
			cout << "----------------------------------------------------------------------" << endl;
			cout << "|                        MIS ACTIVOS RENTADOS                        |" << endl;
			cout << "----------------------------------------------------------------------" << endl;
			us->getInstance()->getUser()->getAssetAVL()->inOrderM();
			system("pause");
			break;
		case '8':
			return;
		default:
			cout << ">> OPCION INCORRECTA" << endl;
			break;
		}
	}
}
