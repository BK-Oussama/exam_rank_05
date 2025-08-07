#include "TreeBag.hpp"
#include <iostream>

TreeBag::TreeBag() : root(NULL) {}

TreeBag::TreeBag(const TreeBag& other) : root(copyNode(other.root)) {}

TreeBag::~TreeBag() {
clear();
}

TreeBag& TreeBag::operator=(const TreeBag& other) {
if (this != &other) {
clear();
root = copyNode(other.root);
}
return *this;
}

TreeBag::Node* TreeBag::extractTree() {
Node* temp = root;
root = NULL;
return temp;
}

void TreeBag::setTree(Node* newRoot) {
clear();
root = newRoot;
}

void TreeBag::insert(int value) {
    Node** current = &root;
    while (*current) {
        if (value < (*current)->value) {
            current = &((*current)->left);
        } else {
            current = &((*current)->right);
        }
    }
    *current = new Node();
    (*current)->value = value;
    (*current)->left = NULL;
    (*current)->right = NULL;
}

void TreeBag::insert(int* array, int size) {
for (int i = 0; i < size; ++i) {
insert(array[i]);
}
}

void TreeBag::print() const {
printNode(root);
std::cout << std::endl;
}

void TreeBag::clear() {
destroyTree(root);
root = NULL;
}

void TreeBag::destroyTree(Node* node) {
if (node) {
destroyTree(node->left);
destroyTree(node->right);
delete node;
}
}

void TreeBag::printNode(Node* node) {
if (node) {
printNode(node->left);
std::cout << node->value << " ";
printNode(node->right);
}
}

TreeBag::Node* TreeBag::copyNode(Node* node) {
    if (!node) return NULL;
    Node* newNode = new Node();
    newNode->value = node->value;
    newNode->left = copyNode(node->left);
    newNode->right = copyNode(node->right);
    return newNode;
}