#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Menu/Menu.h"
#include "Structures/SparseMatrix/SparseMatrix.h"

using namespace std;

int main() {
    srand(time(NULL));

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

    Menu menu;
    return 0;
}
