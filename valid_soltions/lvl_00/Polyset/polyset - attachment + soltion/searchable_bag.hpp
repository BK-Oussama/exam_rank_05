#ifndef SEARCHABLE_BAG_HPP
#define SEARCHABLE_BAG_HPP

#include "bag.hpp"

class searchable_bag : virtual public bag
{
public:
    virtual ~searchable_bag() {}
    virtual bool has(int x) const = 0;
};

#endif
