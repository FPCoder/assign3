#ifndef MATCHTREE_H
#define MATCHTREE_H

#include "Entree.h"
#include "Node.h"

class MatchTree {
public:
    MatchTree();
    void add(Entree);
    void reset() { root = 0; }
    void inorder() { inorder(root); }
private:
    void inorder(Node<vector<Entree>>*);
    Node<vector<Entree>>* add(Node<vector<Entree>>*, Node<Entree>*);
    Node<vector<Entree>> *root;
};

#endif // MATCHTREE_H
