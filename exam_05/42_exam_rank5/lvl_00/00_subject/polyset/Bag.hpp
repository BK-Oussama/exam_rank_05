#ifndef BAG_HPP
#define BAG_HPP

#include <vector>
#include <algorithm>
#include <iostream>

class Bag
{
public:
virtual ~Bag(){};
virtual void insert(int) = 0;
virtual void insert(int*, int) = 0;
virtual void print(void) const = 0;
virtual void clear() = 0;
};

#endif