#include "SplayTreeNode.hh"

bool SplayTreeNode::operator<(const SplayTreeNode& other) {
    return key < other.key;
}
