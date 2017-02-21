#ifndef MENU_H
#define MENU_H

#include <fstream>
#include <vector>
#include "Entree.h"
#include "MatchTree.h"
using namespace std;

class Menu {
public:
    Menu();
    Menu(ifstream&);
    double findMatch(Entree);
	void addToTree(MatchTree tree);
private:
    vector<Entree> entrees;
};

#endif // MENU_H
