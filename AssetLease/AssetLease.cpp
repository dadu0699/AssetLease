#include <iostream>
#include <cstdlib>

#include "Menu/Menu.h"
#include "Structures/AVLTree/AVLTree.h"

using namespace std;

int main() {
    AVLTree* avlTree = new AVLTree();
    avlTree->insert(new Asset("100", "d","D"));
    avlTree->insert(new Asset("29", "a","qweD"));
    avlTree->insert(new Asset("71", "b","Dasd"));
    avlTree->insert(new Asset("82", "c","Das"));
    avlTree->insert(new Asset("48", "e","Dxcx"));
    avlTree->insert(new Asset("39", "asd","Dw"));
    avlTree->insert(new Asset("101", "wqe","D"));
    avlTree->insert(new Asset("22", "d321","Ddsf"));
    avlTree->insert(new Asset("46", "d2","De"));
    avlTree->insert(new Asset("17", "d123","Dersd"));
    avlTree->insert(new Asset("3", "d321","Dasdasdx"));
    avlTree->insert(new Asset("20", "dws","Dwea"));
    avlTree->insert(new Asset("25", "dads","Ddsfds"));
    avlTree->report();


    avlTree->deleteNode("100");
    avlTree->deleteNode("29");
    avlTree->deleteNode("71");
    avlTree->deleteNode("82");
    avlTree->deleteNode("48");
    avlTree->deleteNode("39");
    avlTree->deleteNode("101");
    avlTree->deleteNode("22");
    avlTree->deleteNode("46");
    avlTree->deleteNode("17");
    avlTree->deleteNode("3");
    avlTree->deleteNode("20");
    avlTree->deleteNode("25");
    avlTree->report();

    Menu menu;
    return 0;
}
