#include <iostream>
#include "SplayTree.hh"

using namespace std;

SplayTree::SplayTree() {
    root = 0;
}

void SplayTree::destroyRecursive(SplayTreeNode* root) {
    if (root) {
        destroyRecursive(root->left);
        destroyRecursive(root->right);
        cout << "\nDeleting node " << root->key;
        delete root;
    }
}

SplayTree::~SplayTree() {
    destroyRecursive(root);
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
                        newNode->parent = current;
                        return 0;
                    }
                } else {
                    if (current->right) {
                        current = current->right;
                    } else {
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

SplayTreeNode* SplayTree::find(int key) {
    SplayTreeNode* current = root;
    while (current) {
        if (key == current->key) {
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

SplayTreeNode* SplayTree::splayBottomUp(SplayTreeNode* current) {
    SplayTreeNode *parent = current->parent, *grandParent;
    while (parent) {
        grandParent = parent->parent;
        if (grandParent) {
            if (current == parent->left) {
                if (parent == grandParent->left) {
                    /* zig-zig right-right rotations */
                    current->parent = grandParent->parent;
                    grandParent->parent = parent;
                    parent->parent = current;

                    grandParent->left = parent->right;
                    parent->right = grandParent;
                    parent->left = current->right;
                    current->right = parent;
                } else {
                    /* zig-zag right-left rotations */
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
                    /* zig-zag left-right rotations */
                    current->parent = grandParent->parent;
                    grandParent->parent = current;
                    parent->parent = current;

                    grandParent->left = current->right;
                    parent->right = current->left;
                    current->left = parent;
                    current->right = grandParent;
                } else {
                    /* zig-zig left-left rotations */
                    current->parent = grandParent->parent;
                    grandParent->parent = parent;
                    parent->parent = current;

                    grandParent->right = parent->left;
                    parent->left = grandParent;
                    parent->right = current->left;
                    current->left = parent;
                }
            }
            parent = current->parent;
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
    return current;
}
