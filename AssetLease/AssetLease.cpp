#include <iostream>
#include <ctime>

#include "Menu/Menu.h"
#include "Structures/SparseMatrix/SparseMatrix.h"

using namespace std;

int main()
{
    srand(time(NULL));
    Menu menu;
    menu.interfaceDesign();
    return 0;
}
