#include <iostream>
#include "SplayTree.hh"

using namespace std;

SplayTree::SplayTree() {
    root = 0;
}

void SplayTree::destroy(SplayTreeNode* root) {
    if (root == 0) {
        return;
    } else {
        destroy(root->left);
        destroy(root->right);
        cout << "Deleting node " << root->key << "\n";
        delete root;
    }
}

SplayTree::~SplayTree() {
    destroy(root);
}

void SplayTree::preorder() {
    cout << "\nPreorder traversal\n";
    preorderRecursive(root);
}

void SplayTree::inorder() {
    cout << "\nInorder traversal\n";
    inorderRecursive(root);
}

void SplayTree::postorder() {
    cout << "\nPostorder traversal\n";
    postorderRecursive(root);
}

void SplayTree::preorderRecursive(SplayTreeNode* root) {
    if (root) {
        cout << root->key;
        preorderRecursive(root->left);
        preorderRecursive(root->right);
    }
}

void SplayTree::inorderRecursive(SplayTreeNode* root) {
    if (root) {
        inorderRecursive(root->left);
        cout << root->key;
        inorderRecursive(root->right);
    }
}

void SplayTree::postorderRecursive(SplayTreeNode* root) {
    if (root) {
        postorderRecursive(root->left);
        postorderRecursive(root->right);
        cout << root->key;
    }
}

int SplayTree::add(int key) {
    if (root == 0) {
        root = new SplayTreeNode(key);
    } else {
        SplayTreeNode* current = root;
        SplayTreeNode* newNode = new SplayTreeNode(key);
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
                        return 0;
                    }
                } else {
                    if (current->right) {
                        current = current->right;
                    } else {
                        current->right = newNode;
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}

SplayTreeNode* SplayTree::find(int key) {
    return 0;
}
int SplayTree::remove(int key) {
    return 0;
}
