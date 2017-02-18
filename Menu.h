#ifndef MENU_H
#define MENU_H

#include <fstream>
#include <vector>
#include "Entree.h"
using namespace std;

class Menu {
public:
    Menu();
    Menu(ifstream&);
    double match(Entree);
    vector<Entree> getEntrees() const { return entrees; }
private:
    vector<Entree> entrees;
};

#endif // MENU_H
