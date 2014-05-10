/* Copyright 2014 Gagarine Yaikhom (MIT License) */

#include "SplayTreeNode.hh"

class SplayTree {
public:
    SplayTree();
    ~SplayTree();
    int add(int key);
    SplayTreeNode* find(int key, bool doSplay);
    int remove(int key);
    void preorder();
    void inorder();
    void postorder();

private:
    SplayTreeNode* root;
    void destroyRecursive(SplayTreeNode *root);
    void destroyNonRecursive(SplayTreeNode* root);
    
    void preorderRecursive(SplayTreeNode *root);
    void inorderRecursive(SplayTreeNode *root);
    void postorderRecursive(SplayTreeNode *root);
    SplayTreeNode* splayBottomUp(SplayTreeNode* current);
};
