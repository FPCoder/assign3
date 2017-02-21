#ifndef NODE_H
#define NODE_H

#include <vector>
using namespace std;

template <typename T>
class Node {
public:
	Node() {}
	Node(T dt, Node* l = 0, Node* r = 0) : data(dt), left(l), right(r) {}
    T getData() const { return data; }
    Node* getLeft() const { return left; }
    Node* getRight() const { return right; }
    void setData(T dt) { data = dt; }
	void setLeft(Node* l) { left = l; }
	void setRight(Node* r) { right = r; }
	bool operator==(Node<T> lhs) { return data == lhs; }
private:
    T data;
    Node<T> *left;
    Node<T> *right;
};

#endif // NODE_H
