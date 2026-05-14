#ifndef RBTREE_H
#define RBTREE_H

#include <iostream>
#include <fstream>

using namespace std;

// Node
enum Color { RED, BLACK };

struct Node {
    int data;
    Color color;

    Node* left;
    Node* right;
    Node* parent;

    Node(int value) {
        data = value;
        color = RED;

        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }
};
// tree class
class RBTree {
private:
    Node* root;

    void rotateLeft(Node*& node);
    void rotateRight(Node*& node);
    void fixInsert(Node*& node);

public:
    RBTree();

    void insert(int data);
    void readFromFile(char filename[]);
    void printTree(Node* root, int space = 0);

    bool search(int data);

    void remove(int data);

    Node* minimum(Node* node);
    void transplant(Node* u, Node* v);
    void fixDelete(Node* node); 

  Node* getRoot();
  
};

#endif
