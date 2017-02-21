#include "MatchTree.h"
#include "Node.h"
using namespace std;

MatchTree::MatchTree() {
    root = 0;
}

// public version
void MatchTree::add(Entree dt) {
	vector<Entree> newRoot;
	newRoot.push_back(dt);

    if (root == 0) {
		root = new Node<vector<Entree>>(newRoot);
    }
    else {
        add(root, &newRoot);
    }
}

// private version
vector<Entree>* MatchTree::add(Node<vector<Entree>> *curr, vector<Entree> *node) {
	vector<Entree> *result = new vector<Entree>;
	if (curr->getData().at(0).getName() == node->at(0).getName()) {
		vector<Entree> t;
		result = &curr->getData();
		t = curr->getData();
		t.push_back(node->at(0));
		curr->setData(t);
	}
	else if (curr->getData().at(0).getName() < node->at(0).getName()) {
		if (curr->hasLeft())
			result = add(curr->getLeft(), node);
		else
			curr->setLeft(new Node<vector<Entree>>(*node));
	}
	else {
		if (curr->hasRight())
			result = add(curr->getRight(), node);
		else
			curr->setRight(new Node<vector<Entree>>(*node));
	}
	inorder();//fixme
	cout << endl;//fixme
	return result;
}
/*Node<vector<Entree>>* MatchTree::add(Node<vector<Entree>> *curr, Entree *node) {
    if (curr == 0) {
		Node<vector<Entree>> *newNode = new Node<vector<Entree>>;
		vector<Entree> oldVec = newNode->getData();

		oldVec.push_back(*node);
		newNode->setData(oldVec);
        return newNode;
    }
    else if (curr->getData().at(0).getName() == node->getName()) {
		vector<Entree> oldVec = curr->getData();
		oldVec.push_back(*node);
		curr->setData(oldVec);
    }
    else {
        if (curr->getData().at(0).getName() < node->getName()) {
            curr->setRight(add(curr->getRight(), node));
        }
        else {
            curr->setLeft(add(curr->getLeft(), node));
        }
    }
    return curr;
}*/

void MatchTree::inorder(Node<vector<Entree>> *curr) {
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