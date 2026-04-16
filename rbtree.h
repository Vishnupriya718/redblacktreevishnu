#ifndef RBTREE_H
#define RBTREE_H

#include <iostream>
#include <fstream>

using namespace std;

// STEP 1: Node
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
