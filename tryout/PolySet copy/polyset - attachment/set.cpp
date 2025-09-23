

#include "set.hpp"

set::set() : m_bag(0) {};

set::set(searchable_bag &bag) : m_bag(&bag) {};

set::set(const set &copy) : m_bag(copy.m_bag) {};

set &set::operator=(const set &other)
{
    if (this != &other)
        this->m_bag = other.m_bag;
    return *this;
};

set::~set() {};

bool set::has(int x) const
{
    if (this->m_bag == 0)
        return false;
    
    return this->m_bag->has(x);
};

void set::insert(int x)
{
    if (this->m_bag == 0)
        return ;
    if (this->m_bag->has(x) == false)
        this->m_bag->insert(x);
};

void set::insert(int *array, int n)
{
    if (this->m_bag == 0 || n <= 0 || array == 0)
        return;
        
    int i = 0;
    while (i < n)
    {
        this->insert(array[i]);
        i++;
    }
}

void set::print() const
{
    if (this->m_bag == 0)
        return ;
    this->m_bag->print();
}

void set::clear()
{
    if (this->m_bag == 0)
        return ;
    this->m_bag->clear();
}