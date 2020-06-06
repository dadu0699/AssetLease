#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Menu/Menu.h"
#include "Structures/AVLTree/AVLTree.h"

using namespace std;

int main() {
    srand(time(NULL));

    AVLTree* avlTree = new AVLTree();
    avlTree->insert(new Asset("a",""));
    avlTree->insert(new Asset("b",""));
    avlTree->insert(new Asset("c",""));
    avlTree->insert(new Asset("d",""));
    avlTree->insert(new Asset("e",""));
    avlTree->insert(new Asset("f",""));
    avlTree->insert(new Asset("g",""));
    avlTree->insert(new Asset("h",""));
    avlTree->insert(new Asset("i",""));
    avlTree->insert(new Asset("j",""));
    avlTree->insert(new Asset("k",""));
    avlTree->insert(new Asset("l",""));
    avlTree->insert(new Asset("m",""));
    avlTree->inOrder();
    avlTree->report();
    Menu menu;
    return 0;
}
