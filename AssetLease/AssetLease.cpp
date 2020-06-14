#include <iostream>
#include <ctime>

#include "Menu/Menu.h"
#include "Structures/SparseMatrix/SparseMatrix.h"

using namespace std;

int main()
{
    srand(time(NULL));
    SparseMatrix *sparseMatrix;
    User *u1 = new User("dadu", "123", "Didier Dominguez");
    User *u2 = new User("petit", "123", "Mehdi Benjelloun");
    User *u3 = new User("robin", "123", "Robin Schulz");
    User *u4 = new User("lost", "123", "Felix De Laet");
    User *u5 = new User("alan", "123", "Alan Olav Walker");
    User *u6 = new User("kygo", "123", "Kyrre Gorvell-Dahll");
    User *u7 = new User("zed", "123", "Anton Zaslavski");

    sparseMatrix->getInstance()->addNode("guatemala", "hp", u1);
    sparseMatrix->getInstance()->addNode("guatemala", "dell", u2);
    sparseMatrix->getInstance()->addNode("jalapa", "arbolitos", u3);
    sparseMatrix->getInstance()->addNode("peten", "national", u4);
    sparseMatrix->getInstance()->addNode("jutiapa", "arbolitos", u5);
    sparseMatrix->getInstance()->addNode("jalapa", "arbolitos", u6);
    sparseMatrix->getInstance()->addNode("guatemala", "hp", u7);

    u1->getAssetAVL()->insert(new Asset("laptop", "gaming"));
    u1->getAssetAVL()->insert(new Asset("laptop", "pavilion"));
    u1->getAssetAVL()->insert(new Asset("impresora", "laser"));
    u1->getAssetAVL()->insert(new Asset("teclado", "iluminado"));
    u1->getAssetAVL()->insert(new Asset("mouse", "gaming"));
    u1->getAssetAVL()->insert(new Asset("impresora", "sistema continuo"));
    u2->getAssetAVL()->insert(new Asset("pc", "todo en uno"));
    u2->getAssetAVL()->insert(new Asset("laptop", "allien"));
    u2->getAssetAVL()->insert(new Asset("monitor", "4k"));
    u2->getAssetAVL()->insert(new Asset("mouse", "gaming"));
    u2->getAssetAVL()->insert(new Asset("mouse", "optico"));
    u2->getAssetAVL()->insert(new Asset("laptop", "inspiron"));
    u2->getAssetAVL()->insert(new Asset("pc", "gaming"));
    u2->getAssetAVL()->insert(new Asset("pc", "torre"));
    u2->getAssetAVL()->insert(new Asset("monitor", "HD"));
    u2->getAssetAVL()->insert(new Asset("laptop", "gaming"));
    u3->getAssetAVL()->insert(new Asset("cama", "matrimonial"));
    u3->getAssetAVL()->insert(new Asset("amaca", "pequenia"));
    u3->getAssetAVL()->insert(new Asset("refri", "grande"));
    u5->getAssetAVL()->insert(new Asset("silla", "metalica"));
    u5->getAssetAVL()->insert(new Asset("casa", "arbol"));
    u5->getAssetAVL()->insert(new Asset("parrilla", ""));
    u5->getAssetAVL()->insert(new Asset("amaca", "grande"));
    u5->getAssetAVL()->insert(new Asset("sillas", "blancas"));
    u5->getAssetAVL()->insert(new Asset("bancas", ""));
    u5->getAssetAVL()->insert(new Asset("hielera", "pequenia"));
    u5->getAssetAVL()->insert(new Asset("churraquera", "grande"));
    u5->getAssetAVL()->insert(new Asset("casa", "camping"));

    Menu menu;
    menu.interfaceDesign();
    return 0;
}
