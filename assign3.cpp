#include <iostream>
#include <fstream>
#include <string>
#include "MatchTree.h"
#include "Menu.h"
#include "Entree.h"
using namespace std;

int main(int argc, char *argv[]) {
    ifstream inFS;
    vector<Menu> menus;
    MatchTree tree;
    double avg = 0;

    for (int i = 1; i < argc; ++i) { // put each menu into a Menu object
        inFS.open(argv[i]);
        if (!inFS.is_open()) {
            cout << "File opening error" << endl;
            return 1;
        }
        else {
            Menu mn(inFS);
            menus.push_back(mn);
        }
        inFS.close();
    }

	for (int i = 0; i < menus.size(); ++i) {
		menus.at(i).addToTree(tree);
	}

	tree.inorder();

    return 0;
}