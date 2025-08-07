#ifndef ARRAY_BAG_HPP
#define ARRAY_BAG_HPP

#include "Bag.hpp"
#include <iostream>

class ArrayBag : virtual public Bag {
protected:
int *_data;
int _size;

public:
ArrayBag();
ArrayBag(const ArrayBag& other);
~ArrayBag();
ArrayBag& operator=(const ArrayBag& other);

void insert(int v);
void insert(int* data, int v);
void print() const;
void clear();
};

#endif