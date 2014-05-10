/* Copyright 2014 Gagarine Yaikhom (MIT License) */

#include "SplayTreeNode.hh"

bool SplayTreeNode::operator<(const SplayTreeNode& other) {
    return key < other.key;
}

bool SplayTreeNode::operator==(const SplayTreeNode& other) {
    return key == other.key;
}
