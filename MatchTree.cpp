#include "MatchTree.h"
#include "Node.h"
using namespace std;

MatchTree::MatchTree() {
    root = 0;
}

// public version
void MatchTree::add(Entree dt) {
	Node<Entree> newNode;
	newNode.setData(dt);

    if (root == 0) {
		vector<Entree> newRoot;
		newRoot.push_back(dt);
		root->setData(newRoot);
    }
    else {
        add(root, &newNode);
    }
}

// private version
Node<vector<Entree>>* MatchTree::add(Node<vector<Entree>> *curr, Node<Entree> *node) {
    if (curr == 0) {
		Node<vector<Entree>> newNode;
		vector<Entree> oldVec = newNode.getData();

		oldVec.push_back(node->getData());
		newNode.setData(oldVec);
        return &newNode;
    }
    else if (curr->getData().at(0) == node->getData()) {
		vector<Entree> oldVec;
		oldVec.push_back(node->getData());
		curr->setData(oldVec);
    }
    else {
        if (curr->getData().at(0).getName() < node->getData().getName()) {
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
