#include <vector>
#include "Node.h"
using namespace std;

template<typename T>
Node<T>::Node() {
	data = 0;
    left = 0;
    right = 0;
}

template <typename T>
Node<T>::Node(T dt, Node *l = 0, Node *r = 0) {
    data = dt;
    left = l;
    right = r;
}