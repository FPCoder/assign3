#ifndef MATCHTREE_H
#define MATCHTREE_H

#include "Entree.h"
#include "Node.h"

class MatchTree {
public:
    MatchTree() { rootFlg = false; }
    void add(Entree);
    void inorder() { inorder(root); }
private:
    void inorder(Node< vector<Entree> >*);
    //Node< vector<Entree> >* add(Node< vector<Entree> >*, Entree*);
	vector<Entree>* add(Node< vector<Entree> >*, vector<Entree>*);
    Node< vector<Entree> > *root;
    bool rootFlg;
};

#endif // MATCHTREE_H
