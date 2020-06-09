#include "UserMenu.h"
#include "../Controllers/UserSession.h"
#include "../Structures/SparseMatrix/SparseMatrix.h"

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

	string option;
	string name;
	string description;
	bool lease;

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
		cout << "----- 5. ACTIVOS RENTADOS" << endl;
		cout << "----- 6. MIS ACTIVOS RENTADOS" << endl;
		cout << "----- 7. CERRAR SESION" << endl;
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
			cout << "|                        CATALOGO ACTIVOS                            |" << endl;
			cout << "----------------------------------------------------------------------" << endl;
			sp->getInstance()->printCatalogue();
			cout << "                                ID" << endl;
			cout << ">> ";
			cin.ignore();
			getline(cin, name);
			system("pause");
			break;
		case '5':
			break;
		case '6':
			break;
		case '7':
			return;
		default:
			cout << ">> OPCION INCORRECTA" << endl;
			break;
		}
	}
}
