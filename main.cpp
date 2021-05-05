#include "BST.hpp"
#include <iomanip>
#include <iostream>
using namespace std;

template <typename T>
void inorderPrint(BinaryTree<T>*);

int main() {
    // create the initial BST
    int values[] = {24, 42, 7, 2, 40, 42, 32, 120};
    BST<int>* root = new BST<int>(37);
    for (int i : values) {
        root->insert(i);
    }

    // let the user perform operations
    int userChoice = 5, temp = 0;
    do {
        cout << endl;
        cout << "1. Find\n";
        cout << "2. Insert\n";
        cout << "3. Remove\n";
        cout << "4. Print\n";
        cout << "5. Exit\n";

        cout << "Enter choice: ";
        cin >> userChoice;

        switch (userChoice) {
            case 1:
                cout << "Enter the value to find: ";
                cin >> temp;

                if (root->find(temp)) {
                    cout << "Found it!\n";
                }
                else {
                    cout << "Could not find that value.\n";
                }

                break;

            case 2:
                cout << "Enter the value to insert: ";
                cin >> temp;
                root->insert(temp);
                break;

            case 3:
                cout << "Enter the value to remove: ";
                cin >> temp;
                root->remove(temp);
                break;

            case 4:
                cout << "Height: " << root->height() << endl;
                cout << "Number of Leaves: " << root->numLeaves() << endl;
                cout << "Number of Nodes: " << root->numNodes() << endl;
                cout << "Minimum Value: " << root->getMin() << endl;
                cout << "Inorder traversal:\n";
                inorderPrint(root);
                cout << endl;
                break;
        }
    } while (userChoice != 5);

    // clean up the dynamic memory for the BST
    delete root;

    // terminate
    return 0;
}

template <typename T>
void inorderPrint(BinaryTree<T>* t) {
    if (t == nullptr) {
        return;
    }

    inorderPrint(t->getLeft());
    cout << t->getValue() << ' ';
    inorderPrint(t->getRight());
}
