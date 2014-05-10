/* Copyright 2014 Gagarine Yaikhom (MIT License) */

class SplayTreeNode {
public:
    SplayTreeNode(int keyValue) : key(keyValue) {
        parent = left = right = 0;
    };
    bool operator<(const SplayTreeNode& other);
    bool operator==(const SplayTreeNode& other);

private:
    int key;
    SplayTreeNode *parent, *left, *right;

    friend class SplayTree;
};
