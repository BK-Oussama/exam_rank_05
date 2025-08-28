#ifndef ARRAY_BAG_HPP
#define ARRAY_BAG_HPP

#include "bag.hpp"
#include <cstddef>

class array_bag : virtual public bag
{

protected:
    int *data_;
    int size_;

public:
    array_bag();
    array_bag(const array_bag &other);
    array_bag &operator=(const array_bag &other);
    virtual ~array_bag();

    virtual void insert(int x);
    virtual void insert(int *arr, int n);
    virtual void print() const;
    virtual void clear();

    int size() const;
};

#endif
