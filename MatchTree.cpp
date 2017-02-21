#include "MatchTree.h"
#include "Node.h"
using namespace std;

MatchTree::MatchTree() {
    root = 0;
}

// public version
void MatchTree::add(Entree dt) {
    if (root == 0) {
		vector<Entree> newRoot;
		newRoot.push_back(dt);
		root = new Node<vector<Entree>>(newRoot);
    }
    else {
        add(root, &dt);
    }
}

// private version
Node<vector<Entree>>* MatchTree::add(Node<vector<Entree>> *curr, Entree *node) {
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
}

void MatchTree::inorder(Node<vector<Entree>> *curr) {
    if (curr == 0) { return; }
    else {
        inorder(curr->getLeft());
        cout << curr->getData().at(0) << endl;
        inorder(curr->getRight());
    }
}
