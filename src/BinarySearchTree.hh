/* Copyright 2014 Gagarine Yaikhom (MIT License) */

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

private:
    BinarySearchTreeNode* root;

    void destroyRecursive(BinarySearchTreeNode *root);
    void destroyNonRecursive(BinarySearchTreeNode* root);
    
    void preorderRecursive(BinarySearchTreeNode *root);
    void preorderNonRecursive(BinarySearchTreeNode *root);
    
    void inorderRecursive(BinarySearchTreeNode *root);
    void inorderNonRecursive(BinarySearchTreeNode *root);
    
    void postorderRecursive(BinarySearchTreeNode *root);
    void postorderNonRecursive(BinarySearchTreeNode *root);
};
