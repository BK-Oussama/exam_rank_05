
#ifndef SEARCHABLE_ARRAY_BAG_HPP
#define SEARCHABLE_ARRAY_BAG_HPP

#include "array_bag.hpp"
#include "searchable_bag.hpp"

class searchable_array_bag : public array_bag, public searchable_bag
{
    public:
        searchable_array_bag();
        searchable_array_bag(const searchable_array_bag &copy);
        searchable_array_bag &operator=(const searchable_array_bag &other);
        virtual ~searchable_array_bag();

        virtual bool has(int x) const;
        
};

#endif