#include <vector>
#include "Node.h"
using namespace std;

template<typename T>
Node<T>::Node() {
    left = 0;
    right = 0;
}

template <typename T>
Node<T>::Node(T dt, Node *l, Node *r) {
    data.push_back(dt);
    left = l;
    right = r;
}

template <typename T>
void Node<T>::setLeft(Node *l) {
    left = l;
}

template <typename T>
void Node<T>::setRight(Node *r) {
    right = r;
}
