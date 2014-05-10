/* Copyright 2014 Gagarine Yaikhom (MIT License) */

class SplayTreeNode {
public:
    SplayTreeNode(int keyValue) : key(keyValue) {
        parent = left = right = 0;
        visited = false;
    };
    bool operator<(const SplayTreeNode& other);
    bool operator==(const SplayTreeNode& other);

private:
    int key;
    SplayTreeNode *parent, *left, *right;
    bool visited; /* for tree traversal without stack */

    friend class SplayTree;
};
