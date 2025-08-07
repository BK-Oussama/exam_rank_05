#include "set.hpp"

set::set(searchable_bag& b) : bag_ref(b) {}

void set::insert(int value) {
    if (!bag_ref.has(value)) {
        bag_ref.insert(value);
    }
}

void set::insert(int* values, int count) {
    for (int i = 0; i < count; ++i) {
        insert(values[i]); // has()
    }
}

bool set::has(int value) const {
    return bag_ref.has(value);
}

void set::print() const {
    bag_ref.print();
}

void set::clear() {
    bag_ref.clear();
}

const searchable_bag& set::get_bag() const {
    return bag_ref;
}
