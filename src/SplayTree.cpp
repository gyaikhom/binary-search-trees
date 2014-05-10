/* Copyright 2014 Gagarine Yaikhom (MIT License) */

#include <iostream>
#include "SplayTree.hh"

using namespace std;

SplayTree::SplayTree() {
    root = 0;
}

void SplayTree::destroyRecursive(SplayTreeNode* root) {
    if (root) {
        destroyRecursive(root->left);
        destroyRecursive(root->right);
        cout << "\nDeleting node " << root->key;
        delete root;
    }
}

void SplayTree::destroyNonRecursive(SplayTreeNode* root) {
    SplayTreeNode* temp;
    /* similar to postorder traversal */
    while (root) {
        if (root->left) {
            root = root->left;
            continue;
        } else if (root->right) {
            root = root->right;
            continue;
        }
        temp = root->parent;
        if (temp) {
            if (temp->left == root)
                temp->left = 0;
            else
                temp->right = 0;
        }

        cout << "\nDeleting node " << root->key;
        delete root;
        root = temp;
    };
}

SplayTree::~SplayTree() {
    destroyNonRecursive(root);
}

void SplayTree::preorderRecursive(SplayTreeNode* root) {
    if (root) {
        cout << root->key;
        preorderRecursive(root->left);
        preorderRecursive(root->right);
    }
}

void SplayTree::preorderNonRecursive(SplayTreeNode* root) {
    SplayTreeNode* current = root;
    while (current) {
        if (!current->visited) {
            cout << current->key;
            current->visited = true;
        }

        if (current->left && !current->left->visited) {
            current = current->left;
            continue;
        } else if (current->right && !current->right->visited) {
            current = current->right;
            continue;
        }
        if (current->left)
            current->left->visited = false;
        if (current->right)
            current->right->visited = false;

        current = current->parent;
    };
    root->visited = false;
}

void SplayTree::preorder() {
    cout << "\nPreorder traversal\n";
    preorderNonRecursive(root);
}

void SplayTree::inorderRecursive(SplayTreeNode* root) {
    if (root) {
        inorderRecursive(root->left);
        cout << root->key;
        inorderRecursive(root->right);
    }
}

void SplayTree::inorderNonRecursive(SplayTreeNode* root) {
    SplayTreeNode* current = root;
    while (current) {
        if (current->left && !current->left->visited) {
            current = current->left;
            continue;
        }

        if (!current->visited) {
            cout << current->key;
            current->visited = true;
        }

        if (current->right && !current->right->visited) {
            current = current->right;
            continue;
        }
        if (current->left)
            current->left->visited = false;
        if (current->right)
            current->right->visited = false;
        current = current->parent;
    };
    root->visited = false;
}

void SplayTree::inorder() {
    cout << "\nInorder traversal\n";
    inorderNonRecursive(root);
}

void SplayTree::postorderRecursive(SplayTreeNode* root) {
    if (root) {
        postorderRecursive(root->left);
        postorderRecursive(root->right);
        cout << root->key;
    }
}

void SplayTree::postorderNonRecursive(SplayTreeNode* root) {
    SplayTreeNode* current = root;
    while (current) {
        if (current->left && !current->left->visited) {
            current = current->left;
            continue;
        } else if (current->right && !current->right->visited) {
            current = current->right;
            continue;
        }

        if (!current->visited) {
            cout << current->key;
            current->visited = true;
        }

        if (current->left)
            current->left->visited = false;
        if (current->right)
            current->right->visited = false;
        current = current->parent;
    };
    root->visited = false;
}

void SplayTree::postorder() {
    cout << "\nPostorder traversal\n";
    postorderNonRecursive(root);
}

int SplayTree::add(int key) {
    if (root == 0) {
        root = new SplayTreeNode(key);
    } else {
        SplayTreeNode* current = root;
        SplayTreeNode* newNode = new SplayTreeNode(key);
        while (current) {
            if (*current == *newNode) {
                delete newNode;
                return 1; /* duplicate key */
            } else {
                if (*newNode < *current) {
                    if (current->left) {
                        current = current->left;
                    } else {
                        current->left = newNode;
                        newNode->parent = current;
                        return 0;
                    }
                } else {
                    if (current->right) {
                        current = current->right;
                    } else {
                        current->right = newNode;
                        newNode->parent = current;
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}

SplayTreeNode* SplayTree::find(int key, bool doSplay) {
    SplayTreeNode* current = root;
    while (current) {
        if (key == current->key) {
            if (doSplay) {
                splayBottomUp(current);
            }
            return current;
        } else {
            if (key < current->key) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
    }
    return 0;
}

int SplayTree::remove(int key) {
    return 0;
}

SplayTreeNode* SplayTree::splayBottomUp(SplayTreeNode* current) {
    SplayTreeNode *parent, *grandParent;
    while (1) {
        parent = current->parent;
        if (!parent) {
            break;
        }
        grandParent = parent->parent;
        if (grandParent) {
            if (grandParent->parent) {
                if (grandParent->parent->left == grandParent) {
                    grandParent->parent->left = current;
                } else {
                    grandParent->parent->right = current;
                }
            }
            if (current == parent->left) {
                if (parent == grandParent->left) {
                    cout << "\nZig Zig right-right";
                    /* zig-zig right-right rotations */
                    if (current->right) {
                        current->right->parent = parent;
                    }
                    if (parent->right) {
                        parent->right->parent = grandParent;
                    }

                    current->parent = grandParent->parent;
                    grandParent->parent = parent;
                    parent->parent = current;

                    grandParent->left = parent->right;
                    parent->right = grandParent;
                    parent->left = current->right;
                    current->right = parent;
                } else {
                    cout << "\nZig Zag right-left";
                    /* zig-zag right-left rotations */
                    if (current->left) {
                        current->left->parent = grandParent;
                    }
                    if (current->right) {
                        current->right->parent = parent;
                    }

                    current->parent = grandParent->parent;
                    grandParent->parent = current;
                    parent->parent = current;

                    grandParent->right = current->left;
                    parent->left = current->right;
                    current->right = parent;
                    current->left = grandParent;
                }
            } else {
                if (parent == grandParent->left) {
                    cout << "\nZig Zag left-right";
                    /* zig-zag left-right rotations */
                    if (current->left) {
                        current->left->parent = parent;
                    }
                    if (parent->right) {
                        parent->right->parent = grandParent;
                    }

                    current->parent = grandParent->parent;
                    grandParent->parent = current;
                    parent->parent = current;

                    grandParent->left = current->right;
                    parent->right = current->left;
                    current->left = parent;
                    current->right = grandParent;
                } else {
                    cout << "\nZig Zig left-left";
                    /* zig-zig left-left rotations */
                    if (current->left) {
                        current->left->parent = parent;
                    }
                    if (parent->left) {
                        parent->left->parent = grandParent;
                    }

                    current->parent = grandParent->parent;
                    grandParent->parent = parent;
                    parent->parent = current;

                    grandParent->right = parent->left;
                    parent->left = grandParent;
                    parent->right = current->left;
                    current->left = parent;
                }
            }
        } else {
            if (current == parent->left) {
                /* right rotate */
                parent->left = current->right;
                parent->parent = current;
                current->right = parent;
            } else {
                /* left rotate */
                parent->right = current->left;
                parent->parent = current;
                current->left = parent;
            }
            current->parent = 0;
            break;
        }
    }
    root = current;
    return current;
}
