#pragma once

#include "searchable_bag.hpp"

class set {
private:
    searchable_bag& bag_ref;

public:
    set(searchable_bag& b);

    void insert(int value);
    void insert(int* values, int count);
    bool has(int value) const;

    void print() const;
    void clear();

    const searchable_bag& get_bag() const;
};
