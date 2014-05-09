#include <iostream>
#include "SplayTreeNode.hh"

using namespace std;

int main(int argc, char **argv) {
    SplayTreeNode a(1);
    SplayTreeNode b(2);
    cout << (a < b);
    return 0;
}
