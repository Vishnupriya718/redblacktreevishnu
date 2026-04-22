#include "rbtree.h"

using namespace std;

RBTree::RBTree() {
    root = nullptr;
}

Node* RBTree::getRoot() {
    return root;
}
