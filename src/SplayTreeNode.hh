class SplayTreeNode {
public:
    SplayTreeNode(int keyValue) : key(keyValue) {};
    bool operator<(const SplayTreeNode& other);

private:
    int key;
};
