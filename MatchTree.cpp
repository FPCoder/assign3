#include "MatchTree.h"
#include "Node.h"
using namespace std;

MatchTree::MatchTree() {
    root = 0;
}

void MatchTree::add(Entree dt) {
    Node<Entree> newNode(dt);
    if (root == 0) {
        *root = newNode;
    }
    else {
        add(root, &newNode);
    }
}

Node<Entree>* MatchTree::add(Node<Entree> *curr, Node<Entree> *node) {
    if (curr == 0) {
        return node;
    }
    else if (*curr == *node) {
        curr->addData(node->getData().at(0));
    }
    else {
        if (*curr < *node) {
            curr->setRight(add(curr->getRight(), node));
        }
        else {
            curr->setLeft(add(curr->getLeft(), node));
        }
    }
    return curr;
}

void MatchTree::inorder(Node<Entree> *curr) {
    if (curr == 0) { return; }
    else {
        inorder(curr.getLeft());
        cout << *curr << endl;
        inorder(curr.getRight());
    }
}
