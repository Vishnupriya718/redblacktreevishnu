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


    // FIX RED-BLACK PROPERTIES
    fixInsert(newNode);
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

// ROTATE LEFT
// Moves a node down to the left
void RBTree::rotateLeft(Node*& node) {

    // Get right child
    Node* rightChild = node->right;

    // Move right child's left subtree
    node->right = rightChild->left;

    // Update parent if subtree exists
    if (rightChild->left != nullptr)
        rightChild->left->parent = node;

    // Update parent pointer
    rightChild->parent = node->parent;

    // If node was root
    if (node->parent == nullptr)

        root = rightChild;

    // If node was left child
    else if (node == node->parent->left)

        node->parent->left = rightChild;

    // If node was right child
    else

        node->parent->right = rightChild;

    // Put node on left of rightChild
    rightChild->left = node;

    // Update parent
    node->parent = rightChild;

}
// ROTATE RIGHT
// Mirror of rotateLeft
void RBTree::rotateRight(Node*& node) {

    Node* leftChild = node->left;

    node->left = leftChild->right;

    if (leftChild->right != nullptr)
        leftChild->right->parent = node;

    leftChild->parent = node->parent;

    if (node->parent == nullptr)

        root = leftChild;

    else if (node == node->parent->right)

        node->parent->right = leftChild;

    else

        node->parent->left = leftChild;

    leftChild->right = node;

    node->parent = leftChild;

}
// FIX INSERT
// Fixes Red-Black Tree violations
void RBTree::fixInsert(Node*& node) {

    // While parent exists and is RED
    while (node != root && node->parent->color == RED) {

        Node* parent = node->parent;
        Node* grandparent = parent->parent;

        
        // CASE: Parent is LEFT child
        if (parent == grandparent->left) {

            Node* uncle = grandparent->right;

            // CASE 1: Uncle is RED
            // Recolor and move up
            if (uncle != nullptr && uncle->color == RED) {

                parent->color = BLACK;
                uncle->color = BLACK;
                grandparent->color = RED;

                node = grandparent;

            }

            else {

                // CASE 2: Triangle
                if (node == parent->right) {

                    node = parent;
                    rotateLeft(node);

                }

                // CASE 3: Line
                parent->color = BLACK;
                grandparent->color = RED;

                rotateRight(grandparent);

            }

        }

      
        // CASE: Parent is RIGHT child
       
        else {

            Node* uncle = grandparent->left;

            // CASE 1: Uncle is RED
            if (uncle != nullptr && uncle->color == RED) {

                parent->color = BLACK;
                uncle->color = BLACK;
                grandparent->color = RED;

                node = grandparent;

            }

            else {

                // CASE 2: Triangle
                if (node == parent->left) {

                    node = parent;
                    rotateRight(node);

                }

                // CASE 3: Line
                parent->color = BLACK;
                grandparent->color = RED;

                rotateLeft(grandparent);

            }

        }

    }

    // Root must always be BLACK
    root->color = BLACK;

}
