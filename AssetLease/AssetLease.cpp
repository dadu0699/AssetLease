#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Menu/Menu.h"

using namespace std;

int main()
{
    srand(time(NULL));
    Menu menu;
    menu.interfaceDesign();
    return 0;
}
