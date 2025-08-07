#include "Set.hpp"
#include <iostream>

Set::Set(SearchableBag* bag) : bag(bag) {}

Set::Set(const Set& other) : bag(other.bag) {} // Shallow copy

Set::~Set() {
}

Set& Set::operator=(const Set& other) {
    if (this != &other) {
        bag = other.bag; // Shallow copy
    }
    return *this;
}

void Set::insert(int value) {
    if (!bag->has(value)) {
        bag->insert(value);
    }
}

void Set::insert(int* values, int size) {
    if (!values || size <= 0)
        return;
        
    for (int i = 0; i < size; i++) {
        if (!bag->has(values[i])) {
            bag->insert(values[i]);
        }
    }
}

bool Set::has(int value) const {
    return bag->has(value);
}

void Set::print() const {
    bag->print();
}

void Set::clear() {
    bag->clear();
}