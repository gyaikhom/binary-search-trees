/* Copyright 2014 Gagarine Yaikhom (MIT License) */

#ifndef BINARY_SEARCH_TREE_NODE_HH
#define	BINARY_SEARCH_TREE_NODE_HH

#include <iostream>

using namespace std;

class SplayTree;

class BinarySearchTreeNode {
public:
    BinarySearchTreeNode(int keyValue) : key(keyValue) {
        parent = left = right = 0;
        visited = false;
    };
    bool operator<(const BinarySearchTreeNode& other);
    bool operator==(const BinarySearchTreeNode& other);
    void print() {
        cout << key << " ";
    }

protected:
    int key;
    BinarySearchTreeNode *parent, *left, *right;
    bool visited; /* for tree traversal without stack */

    friend class BinarySearchTree;
    friend class SplayTree;
};

#endif