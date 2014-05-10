/* Copyright 2014 Gagarine Yaikhom (MIT License) */

#ifndef SPLAY_TREE_HH
#define	SPLAY_TREE_HH

#include "BinarySearchTree.hh"

class SplayTree : public BinarySearchTree {
public:
    SplayTree();
    ~SplayTree();
    int add(int key);
    int remove(int key);
    BinarySearchTreeNode* find(int key);

private:
    void splayBottomUp(BinarySearchTreeNode* current);
};

#endif