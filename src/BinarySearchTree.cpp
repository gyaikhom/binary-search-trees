/* Copyright 2014 Gagarine Yaikhom (MIT License) */

#include <iostream>
#include "BinarySearchTree.hh"

using namespace std;

BinarySearchTree::BinarySearchTree() {
    root = 0;
}

void BinarySearchTree::preorderRecursive(BinarySearchTreeNode* root) {
    if (root) {
        root->print();
        preorderRecursive(root->left);
        preorderRecursive(root->right);
    }
}

void BinarySearchTree::preorderNonRecursive(BinarySearchTreeNode* root) {
    BinarySearchTreeNode* current = root;
    while (current) {
        if (!current->visited) {
            current->print();
            current->visited = true;
        }

        if (current->left && !current->left->visited) {
            current = current->left;
            continue;
        } else if (current->right && !current->right->visited) {
            current = current->right;
            continue;
        }

        if (current->left)
            current->left->visited = false;
        if (current->right)
            current->right->visited = false;

        current = current->parent;
    };
    root->visited = false;
}

void BinarySearchTree::preorder() {
    cout << "\nPreorder traversal\n";
    preorderNonRecursive(root);
}

void BinarySearchTree::inorderRecursive(BinarySearchTreeNode* root) {
    if (root) {
        inorderRecursive(root->left);
        root->print();
        inorderRecursive(root->right);
    }
}

void BinarySearchTree::inorderNonRecursive(BinarySearchTreeNode* root) {
    BinarySearchTreeNode* current = root;
    while (current) {
        if (current->left && !current->left->visited) {
            current = current->left;
            continue;
        }

        if (!current->visited) {
            current->print();
            current->visited = true;
        }

        if (current->right && !current->right->visited) {
            current = current->right;
            continue;
        }

        if (current->left)
            current->left->visited = false;
        if (current->right)
            current->right->visited = false;

        current = current->parent;
    };
    root->visited = false;
}

void BinarySearchTree::inorder() {
    cout << "\nInorder traversal\n";
    inorderNonRecursive(root);
}

void BinarySearchTree::postorderRecursive(BinarySearchTreeNode* root) {
    if (root) {
        postorderRecursive(root->left);
        postorderRecursive(root->right);
        root->print();
    }
}

void BinarySearchTree::postorderNonRecursive(BinarySearchTreeNode* root) {
    BinarySearchTreeNode* current = root;
    while (current) {
        if (current->left && !current->left->visited) {
            current = current->left;
            continue;
        } else if (current->right && !current->right->visited) {
            current = current->right;
            continue;
        }

        if (!current->visited) {
            current->print();
            current->visited = true;
        }

        if (current->left)
            current->left->visited = false;
        if (current->right)
            current->right->visited = false;

        current = current->parent;
    };
    root->visited = false;
}

void BinarySearchTree::postorder() {
    cout << "\nPostorder traversal\n";
    postorderNonRecursive(root);
}

int BinarySearchTree::add(int key) {
    if (root == 0) {
        root = new BinarySearchTreeNode(key);
    } else {
        BinarySearchTreeNode* current = root;
        BinarySearchTreeNode* newNode = new BinarySearchTreeNode(key);
        while (current) {
            if (*current == *newNode) {
                delete newNode;
                return 1; /* duplicate key */
            } else {
                if (*newNode < *current) {
                    if (current->left)
                        current = current->left;
                    else {
                        current->left = newNode;
                        newNode->parent = current;
                        return 0;
                    }
                } else {
                    if (current->right)
                        current = current->right;
                    else {
                        current->right = newNode;
                        newNode->parent = current;
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}

BinarySearchTreeNode* BinarySearchTree::find(int key) {
    BinarySearchTreeNode* current = root;
    while (current) {
        if (key == current->key)
            return current;
        else {
            if (key < current->key)
                current = current->left;
            else
                current = current->right;
        }
    }
    return 0;
}

int BinarySearchTree::remove(int key) {
    return 0;
}

void BinarySearchTree::destroyRecursive(BinarySearchTreeNode* root) {
    if (root) {
        destroyRecursive(root->left);
        destroyRecursive(root->right);
        cout << "\nDeleting node " << root->key;
        delete root;
    }
}

void BinarySearchTree::destroyNonRecursive(BinarySearchTreeNode* root) {
    BinarySearchTreeNode* temp;
    while (root) {
        if (root->left) {
            root = root->left;
            continue;
        } else if (root->right) {
            root = root->right;
            continue;
        }

        temp = root->parent;
        if (temp) {
            if (temp->left == root)
                temp->left = 0;
            else
                temp->right = 0;
        }

        cout << "\nDeleting node " << root->key;
        delete root;
        root = temp;
    };
}

BinarySearchTree::~BinarySearchTree() {
    destroyNonRecursive(root);
}
