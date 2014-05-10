/* Copyright 2014 Gagarine Yaikhom (MIT License) */

#include "BinarySearchTreeNode.hh"

bool BinarySearchTreeNode::operator<(const BinarySearchTreeNode& other) {
    return key < other.key;
}

bool BinarySearchTreeNode::operator==(const BinarySearchTreeNode& other) {
    return key == other.key;
}
