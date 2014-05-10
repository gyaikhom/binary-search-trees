/* Copyright 2014 Gagarine Yaikhom (MIT License) */

#include <iostream>
#include "BinarySearchTree.hh"
#include "SplayTree.hh"

using namespace std;

void testBinarySearchTree() {
    cout << "Testing Binary Search Tree...";
    BinarySearchTree tree;
    tree.add(5);
    tree.add(4);
    tree.add(6);
    tree.add(8);
    tree.add(3);
    tree.add(1);
    tree.add(9);
    tree.add(7);

    tree.preorder();
    tree.inorder();
    tree.postorder();

    BinarySearchTreeNode* node = tree.find(2);
    if (node) {
        cout << "\nFound node with key " << 2;
    } else {
        cout << "\nCould not find node with key " << 2;
    }

    node = tree.find(1);
    if (node) {
        cout << "\nFound node with key " << 1;
    } else {
        cout << "\nCould not find node with key " << 1;
    }
}

void testSplayTree() {
    cout << "\n\nTesting Splay Tree...";
    SplayTree tree;
    tree.add(5);
    tree.add(4);
    tree.add(6);
    tree.add(8);
    tree.add(3);
    tree.add(1);
    tree.add(9);
    tree.add(7);

    tree.preorder();
    tree.inorder();
    tree.postorder();

    BinarySearchTreeNode* node = tree.find(2);
    if (node) {
        cout << "\nFound node with key " << 2;
    } else {
        cout << "\nCould not find node with key " << 2;
    }

    node = tree.find(1);
    if (node) {
        cout << "\nFound node with key " << 1;
    } else {
        cout << "\nCould not find node with key " << 1;
    }
    tree.preorder();

    node = tree.find(1);
    if (node) {
        cout << "\nFound node with key " << 1;
    } else {
        cout << "\nCould not find node with key " << 1;
    }
    tree.preorder();
}

int main(int argc, char **argv) {
    testBinarySearchTree();
    testSplayTree();
    return 0;
    ;
}
