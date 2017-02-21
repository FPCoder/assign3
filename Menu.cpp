#include <fstream>
#include <string>
#include <vector>
#include "Menu.h"
#include "Entree.h"
#include "MatchTree.h"
using namespace std;

Menu::Menu() {

}

Menu::Menu(ifstream &inFS) {
    string itm; // new item name
    double prc; // new price
    Entree ent;

    while (inFS >> itm >> prc) {
		cout << itm << prc << endl;
        ent.setName(itm);
        ent.setPrice(prc);
        entrees.push_back(ent);
    }
}

void Menu::addToTree(MatchTree tree) {
	for (int i = 0; i < entrees.size(); ++i) {
		tree.add(entrees.at(i));
	}
}