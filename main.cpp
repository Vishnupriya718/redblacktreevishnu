#include "rbtree.h"

using namespace std;

int main() {
    RBTree tree;

    int choice;
    int number;
    char filename[50];

    do {
        cout << "\n1. Insert\n";
        cout << "2. Read File\n";
        cout << "3. Print\n";
        cout << "4. Search\n";
        cout << "5. Remove\n";
        cout << "6. Exit\n";

        cout << "Choice: ";
        cin >> choice;


        // INSERT

        if (choice == 1) {

            cout << "Enter number: ";
            cin >> number;

            if (number >= 1 && number <= 999)
                tree.insert(number);
            else
                cout << "Number must be 1-999." << endl;
        }


        // READ FILE

        else if (choice == 2) {

            cout << "Filename: ";
            cin >> filename;

            tree.readFromFile(filename);
        }


        // PRINT

        else if (choice == 3) {

            tree.printTree(tree.getRoot(), 0);
        }


        // SEARCH

        else if (choice == 4) {

            cout << "Enter number to search: ";
            cin >> number;

            if (tree.search(number))
                cout << "Found in tree." << endl;
            else
                cout << "Not found." << endl;
        }

        // REMOVE
 
        else if (choice == 5) {

            cout << "Enter number to remove: ";
            cin >> number;

            tree.remove(number);
        }

    } while (choice != 6);

    return 0;
}
