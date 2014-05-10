/* Copyright 2014 Gagarine Yaikhom (MIT License) */

#include <iostream>
#include "SplayTree.hh"

using namespace std;

SplayTree::SplayTree() {
    root = 0;
}

SplayTree::~SplayTree() {
}

int SplayTree::add(int key) {
    if (root == 0) {
        root = new BinarySearchTreeNode(key);
        return 0;
    }

    BinarySearchTreeNode* current = root;
    BinarySearchTreeNode* newNode = new BinarySearchTreeNode(key);
    while (current) {
        if (*current == *newNode) {
            delete newNode;
            return 1; /* duplicate key */
        } else {
            if (*newNode < *current) {
                if (current->left) {
                    current = current->left;
                } else {
                    current->left = newNode;
                    newNode->parent = current;
                    goto splay;
                }
            } else {
                if (current->right) {
                    current = current->right;
                } else {
                    current->right = newNode;
                    newNode->parent = current;
                    goto splay;
                }
            }
        }
    }

splay:
    splayBottomUp(current);
    return 0;
}

BinarySearchTreeNode* SplayTree::find(int key) {
    BinarySearchTreeNode* current = root;
    while (current) {
        if (key == current->key) {
            splayBottomUp(current);
            return current;
        } else {
            if (key < current->key) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
    }
    return 0;
}

int SplayTree::remove(int key) {
    return 0;
}

BinarySearchTreeNode* SplayTree::splayBottomUp(BinarySearchTreeNode* current) {
    BinarySearchTreeNode *parent, *grandParent;
    while (1) {
        parent = current->parent;
        if (!parent) {
            break;
        }
        grandParent = parent->parent;
        if (grandParent) {
            if (grandParent->parent) {
                if (grandParent->parent->left == grandParent) {
                    grandParent->parent->left = current;
                } else {
                    grandParent->parent->right = current;
                }
            }
            if (current == parent->left) {
                if (parent == grandParent->left) {
                    cout << "\nZig Zig right-right";
                    /* zig-zig right-right rotations */
                    if (current->right) {
                        current->right->parent = parent;
                    }
                    if (parent->right) {
                        parent->right->parent = grandParent;
                    }

                    current->parent = grandParent->parent;
                    grandParent->parent = parent;
                    parent->parent = current;

                    grandParent->left = parent->right;
                    parent->right = grandParent;
                    parent->left = current->right;
                    current->right = parent;
                } else {
                    cout << "\nZig Zag right-left";
                    /* zig-zag right-left rotations */
                    if (current->left) {
                        current->left->parent = grandParent;
                    }
                    if (current->right) {
                        current->right->parent = parent;
                    }

                    current->parent = grandParent->parent;
                    grandParent->parent = current;
                    parent->parent = current;

                    grandParent->right = current->left;
                    parent->left = current->right;
                    current->right = parent;
                    current->left = grandParent;
                }
            } else {
                if (parent == grandParent->left) {
                    cout << "\nZig Zag left-right";
                    /* zig-zag left-right rotations */
                    if (current->left) {
                        current->left->parent = parent;
                    }
                    if (parent->right) {
                        parent->right->parent = grandParent;
                    }

                    current->parent = grandParent->parent;
                    grandParent->parent = current;
                    parent->parent = current;

                    grandParent->left = current->right;
                    parent->right = current->left;
                    current->left = parent;
                    current->right = grandParent;
                } else {
                    cout << "\nZig Zig left-left";
                    /* zig-zig left-left rotations */
                    if (current->left) {
                        current->left->parent = parent;
                    }
                    if (parent->left) {
                        parent->left->parent = grandParent;
                    }

                    current->parent = grandParent->parent;
                    grandParent->parent = parent;
                    parent->parent = current;

                    grandParent->right = parent->left;
                    parent->left = grandParent;
                    parent->right = current->left;
                    current->left = parent;
                }
            }
        } else {
            if (current == parent->left) {
                /* right rotate */
                parent->left = current->right;
                parent->parent = current;
                current->right = parent;
            } else {
                /* left rotate */
                parent->right = current->left;
                parent->parent = current;
                current->left = parent;
            }
            current->parent = 0;
            break;
        }
    }
    root = current;
    return current;
}
