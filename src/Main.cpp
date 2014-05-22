/* Copyright 2014 Gagarine Yaikhom (MIT License) */

#include <iostream>
#include "BinarySearchTree.hh"
#include "SplayTree.hh"

using namespace std;

void test() {
    cout << "Testing Binary Search Tree...";
    SplayTree tree;
    char input;
    int value;
    string helpMsg = "\nq - quit\na - add node\nr - remove node\nf - find node\n"
            "p - pre-order traversal\ni - in-order traversal\no - post-order traversal";

    cout << helpMsg << "\n? ";
    cin >> input;
    while (input != 'q') {
        switch (input) {
            case 'a':
                cout << "Key to add: ";
                cin >> value;
                tree.add(value);
                break;

            case 'r':
                cout << "Key to remove: ";
                cin >> value;
                if (tree.remove(value))
                    cout << "Node was removed";
                else
                    cout << "Could not find node";
                break;

            case 'f':
                cout << "Key to find: ";
                cin >> value;
                if (tree.find(value))
                    cout << "Found node";
                else
                    cout << "Could not find node";
                break;

            case 'p':
                tree.preorder();
                break;

            case 'i':
                tree.inorder();
                break;

            case 'o':
                tree.postorder();
                break;

            default:
                cout << helpMsg;
        }
        cout << "\n? ";
        cin >> input;
    }
}

int main(int argc, char **argv) {
    test();
    return 0;
}
