#ifndef NODE_H
#define NODE_H

#include <vector>
using namespace std;

template <typename T>
class Node {
public:
    Node();
    Node(T, Node* l = 0, Node* r = 0);
    vector<T> getData() const { return data; }
    Node* getLeft() const { return left; }
    Node* getRight() const { return right; }
    void addData(T dt) { data.push_back(dt); }
    void setLeft(Node*);
    void setRight(Node*);
    bool operator==(Node<T> lhs) { return lhs.getData() == data; }
    bool operator<(Node<T> lhs) { return data < lhs; }
    bool operator>(Node<T> lhs) { return data > lhs; }
private:
    vector<T> data;
    Node<T> *left;
    Node<T> *right;
};

#endif // NODE_H
