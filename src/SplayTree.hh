#include "SplayTreeNode.hh"

class SplayTree {
public:
    SplayTree();
    ~SplayTree();
    int add(int key);
    SplayTreeNode* find(int key);
    int remove(int key);

private:
    SplayTreeNode* root;
    void destroy(SplayTreeNode *root);
};
