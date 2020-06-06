#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Menu/Menu.h"
#include "Structures/SparseMatrix/SparseMatrix.h"
#include "Structures/AVLTree/AVLTree.h"

using namespace std;

int main() {
    srand(time(NULL));

    AVLTree *avl = new AVLTree();
    avl->insert(new Asset("a", ""));
    avl->insert(new Asset("b", ""));
    avl->insert(new Asset("c", ""));
    avl->insert(new Asset("d", ""));
    avl->insert(new Asset("e", ""));
    avl->insert(new Asset("f", ""));
    avl->insert(new Asset("g", ""));
    avl->insert(new Asset("h", ""));
    avl->report();

    SparseMatrix* sp = new SparseMatrix();
    sp->addNode("Guatemala",    "HP",           new User("U1",   "admin", "Didier"));
    sp->addNode("Guatemala",    "HP",           new User("U2",   "admin", "Didier"));
    sp->addNode("Huehue",       "DD",           new User("U3",   "admin", "Didier"));
    sp->addNode("Solola",       "HP",           new User("U4",   "admin", "Didier"));
    sp->addNode("Reu",          "Wallmart",     new User("U5",   "admin", "Didier"));
    sp->addNode("Xela",         "USAC",         new User("U6",   "admin", "Didier"));
    sp->addNode("Guatemala",    "rr",           new User("U7",   "admin", "Didier"));
    sp->addNode("Huehue",       "Wallmart",     new User("U8",   "admin", "Didier"));
    sp->addNode("Xela",         "Wallmart",     new User("U9",   "admin", "Didier"));
    sp->addNode("Xela",         "HP",           new User("U0",   "admin", "Didier"));
    sp->printColumnHeaders();
    sp->printRowHeaders();
    sp->printColumns();
    sp->printRows();
    sp->report();


    Menu menu;
    return 0;
}
