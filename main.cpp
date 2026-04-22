#include "rbtree.h"

using namespace std;

int main() {
    RBTree tree;

    int choice;
    int number;
    char filename[50];

    do {
        cout << "\n1. Insert\n2. Read File\n3. Print\n4. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter number: ";
            cin >> number;
            tree.insert(number);
        }

        else if (choice == 2) {
            cout << "Filename: ";
            cin >> filename;
            tree.readFromFile(filename);
        }

        else if (choice == 3) {
            tree.printTree(tree.getRoot(), 0);
        }

    } while (choice != 4);

    return 0;
}
