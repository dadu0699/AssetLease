#include <iostream>
#include <cstdlib>

#include "Menu/Menu.h"
#include "Structures/AVLTree/AVLTree.h"

using namespace std;

int main() {
    AVLTree* avlTree = new AVLTree();
    avlTree->insert(new Asset("ARBOL", "d","D"));
    avlTree->insert(new Asset("ARBOLL", "d","D"));
    avlTree->insert(new Asset("BOTE", "d","D"));
    avlTree->insert(new Asset("arbol", "d","D"));
    avlTree->insert(new Asset("bote", "d","D"));
    avlTree->report();

    Menu menu;
    return 0;
}
