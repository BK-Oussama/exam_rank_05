#ifndef SET_HPP
#define SET_HPP

#include "searchable_bag.hpp"

class set : public searchable_bag
{

private:
    searchable_bag *m_set_bag;

public:
    set();
    set(const searchable_bag &bag);
    set(const set &copy);
    set &operator=(const set &other);
    ~set();

    virtual bool has(int x) const;

    virtual void insert(int x);
    virtual void insert(int *array, int x);
    virtual void print() const;
    virtual void clear();
};

#endif