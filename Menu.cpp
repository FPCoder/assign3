#include <fstream>
#include <string>
#include <vector>
#include "Menu.h"
#include "Entree.h"
using namespace std;

Menu::Menu() {

}

Menu::Menu(ifstream &inFS) {
    int i = 0;
    string itm; // new item name
    double prc; // new price
    Entree ent;

    while (!inFS.eof()) {
        inFS >> itm >> prc;
        ent.setName(itm);
        ent.setPrice(prc);
        entrees.push_back(ent);
    }
}

double Menu::findMatch(Entree ent) { // finds the price of a matching entree
    string str = ent.getName();

    for (int i = 0; i < entrees.size(); ++i) {
        if (ent == entrees.at(i)) {
            return entrees.at(i).getPrice();
        }
    }
    return -1; // indicates no matching entree
}
