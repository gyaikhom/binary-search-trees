class SplayTreeNode {
public:
    SplayTreeNode(int keyValue) : key(keyVale) {};
    bool operator<(const SplayTreeNode& other);

private:
    int key;
};
