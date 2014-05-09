class SplayTreeNode {
public:
    int key;
    SplayTreeNode *parent, *left, *right;
    SplayTreeNode(int keyValue) : key(keyValue) {
        parent = left = right = 0;
    };
    bool operator<(const SplayTreeNode& other);
};
