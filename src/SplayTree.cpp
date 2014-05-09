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
        cout << "Deleting node " << root->key;
        delete root;
    }
}

SplayTree::~SplayTree() {
    destroy(root);
}

int SplayTree::add(int key) {
    if (root == 0) {
        root = new SplayTreeNode(key);
    }
    return 0;
}

SplayTreeNode* SplayTree::find(int key) {
    return 0;
}
int SplayTree::remove(int key) {
    return 0;
}
