/* Copyright 2014 Gagarine Yaikhom (MIT License) */

#ifndef BINARY_SEARCH_TREE_HH
#define	BINARY_SEARCH_TREE_HH

#include "BinarySearchTreeNode.hh"

class BinarySearchTree {
public:
    BinarySearchTree();
    ~BinarySearchTree();

    int add(int key);
    int remove(int key);
    void preorder();
    void inorder();
    void postorder();
    BinarySearchTreeNode* find(int key);

    BinarySearchTreeNode* min() {
        return findSubtreeMin(root);
    };

    BinarySearchTreeNode* max() {
        return findSubtreeMax(root);
    };

protected:
    BinarySearchTreeNode* root;

    BinarySearchTreeNode* findSubtreeMin(BinarySearchTreeNode* root);
    BinarySearchTreeNode* findSubtreeMax(BinarySearchTreeNode* root);

    void removeNode(BinarySearchTreeNode *node);

    void destroyRecursive(BinarySearchTreeNode *root);
    void destroyNonRecursive(BinarySearchTreeNode* root);

    void preorderRecursive(BinarySearchTreeNode *root);
    void preorderNonRecursive(BinarySearchTreeNode *root);

    void inorderRecursive(BinarySearchTreeNode *root);
    void inorderNonRecursive(BinarySearchTreeNode *root);

    void postorderRecursive(BinarySearchTreeNode *root);
    void postorderNonRecursive(BinarySearchTreeNode *root);
};

#endif
