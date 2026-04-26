#include "rbtree.h"

using namespace std;

// Constructor
RBTree::RBTree() {
    root = nullptr;
}

// Get root
Node* RBTree::getRoot() {
    return root;
}

// Insert (basic BST version for now)
void RBTree::insert(int data) {
    Node* newNode = new Node(data);

    Node* parent = nullptr;
    Node* current = root;

    while (current != nullptr) {
        parent = current;

        if (data < current->data)
            current = current->left;
        else
            current = current->right;
    }

    newNode->parent = parent;

    if (parent == nullptr)
        root = newNode;

    else if (data < parent->data)
        parent->left = newNode;

    else
        parent->right = newNode;
}

// Read numbers from file
void RBTree::readFromFile(char filename[]) {
    ifstream file(filename);

    if (!file) {
        cout << "Cannot open file." << endl;
        return;
    }

    int num;

    while (file >> num) {
        insert(num);
    }

    file.close();
}

// Print tree visually
void RBTree::printTree(Node* root, int space) {
    if (root == nullptr)
        return;

    space += 10;

    printTree(root->right, space);

    cout << endl;

    for (int i = 10; i < space; i++)
        cout << " ";

    cout << root->data;

    if (root->color == RED)
        cout << "(R)";
    else
        cout << "(B)";

    if (root->parent != nullptr)
        cout << " P:" << root->parent->data;

    cout << endl;

    printTree(root->left, space);
}
