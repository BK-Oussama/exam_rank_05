
#ifndef SET_HPP
#define SET_HPP

#include "searchable_bag.hpp"


class set : public searchable_bag
{
    private:
        searchable_bag *bag_;
    
    public:
        set();
        set(searchable_bag &backend);

        set(const set &copy);
        set &operator=(const set &other);
        virtual ~set();

        virtual bool has(int x) const;

        virtual void insert(int x);
        virtual void insert(int *arr, int n);
        virtual void print()const;
        virtual void clear();

};

#endif