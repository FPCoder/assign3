#include "MatchTree.h"
#include "Node.h"
using namespace std;

// public version
void MatchTree::add(Entree dt) {
	    vector<Entree> newRoot;
	    newRoot.push_back(dt);

    if (rootFlg == false) {
		root = new Node< vector<Entree> >(newRoot);
        rootFlg = true;
    }
    else {
        add(root, &newRoot);
    }
}

// private version
vector<Entree>* MatchTree::add(Node< vector<Entree> > *curr, vector<Entree> *node) {
	vector<Entree> *result = new vector<Entree>;
	if (curr->getData().at(0).getName() == node->at(0).getName()) {
		vector<Entree> t;
		*result = curr->getData();
		t = curr->getData();
		t.push_back(node->at(0));
		curr->setData(t);
	}
	else if (curr->getData().at(0).getName() < node->at(0).getName()) {
		if (curr->hasLeft())
			result = add(curr->getLeft(), node);
		else
			curr->setLeft(new Node< vector<Entree> >(*node));
	}
	else {
		if (curr->hasRight())
			result = add(curr->getRight(), node);
		else
			curr->setRight(new Node< vector<Entree> >(*node));
	}
	return result;
}

void MatchTree::inorder(Node< vector<Entree> > *curr) {
    if (curr == 0) { return; }
    else {
        inorder(curr->getLeft());
		double avg = 0;
		for (int i = 0; i < curr->getData().size(); ++i) {
			avg += curr->getData().at(i).getPrice();
		}
		cout << curr->getData().at(0).getName() << " " << avg / curr->getData().size() << endl;
        inorder(curr->getRight());
    }
}
