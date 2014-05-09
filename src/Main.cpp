#include <iostream>
#include "SplayTree.hh"

using namespace std;

int main(int argc, char **argv) {
    SplayTree tree;
    tree.add(5);
    tree.add(4);
    tree.add(6);
    tree.add(8);
    tree.add(3);
    tree.add(1);
    tree.add(9);
    tree.add(7);

    tree.preorder();
    tree.inorder();
    tree.postorder();
    return 0;
}
