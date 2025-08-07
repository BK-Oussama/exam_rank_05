#include "searchable_tree_bag.hpp"

SearchableTreeBag::SearchableTreeBag() : TreeBag() {}

SearchableTreeBag::SearchableTreeBag(const SearchableTreeBag& other) : TreeBag(other) {}

SearchableTreeBag::~SearchableTreeBag(){}

SearchableTreeBag& SearchableTreeBag::operator=(const SearchableTreeBag& other) {
    if (this != &other) {
        TreeBag::operator=(other);
    }
    return *this;
}

bool SearchableTreeBag::has(int value) const {
    Node* current = root;
    while (current) {
        if (current->value == value) {
            return true;
        } else if (current->value > value) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return false;
}