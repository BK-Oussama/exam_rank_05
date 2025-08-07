#include "searchable_array_bag.hpp"
#include <iostream>

SearchableArrayBag::SearchableArrayBag() : ArrayBag() {}

SearchableArrayBag::SearchableArrayBag(const SearchableArrayBag& other) : ArrayBag(other) {}

SearchableArrayBag::~SearchableArrayBag() {}

SearchableArrayBag& SearchableArrayBag::operator=(const SearchableArrayBag& other) {
    if (this != &other) {
        ArrayBag::operator=(other);
    }
    return *this;
}

bool SearchableArrayBag::has(int value) const {
    for (int i = 0; i < _size; ++i) {
        if (_data[i] == value) {
            return true;
        }
    }
    return false;
}