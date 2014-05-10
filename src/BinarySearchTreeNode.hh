/* Copyright 2014 Gagarine Yaikhom (MIT License) */

class BinarySearchTreeNode {
public:
    BinarySearchTreeNode(int keyValue) : key(keyValue) {
        parent = left = right = 0;
        visited = false;
    };
    bool operator<(const BinarySearchTreeNode& other);
    bool operator==(const BinarySearchTreeNode& other);

private:
    int key;
    BinarySearchTreeNode *parent, *left, *right;
    bool visited; /* for tree traversal without stack */

    friend class BinarySearchTree;
};
