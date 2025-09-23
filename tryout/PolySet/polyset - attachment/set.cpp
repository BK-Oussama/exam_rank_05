
#include "set.hpp"

set::set() : m_set_bag(0) {};

set::set(const searchable_bag &bag) : m_set_bag(const_cast<searchable_bag *>(&bag)) {};

set::set(const set &copy) : m_set_bag(copy.m_set_bag) {};

set &set::operator=(const set &other)
{
    if (this != &other)
        m_set_bag = other.m_set_bag;

    return *this;
}

set::~set() {};

bool set::has(int x) const
{
    if (m_set_bag == 0)
        return false;
    if (m_set_bag->has(x))
        return true;
    return false;
}

void set::insert(int x)
{
    if (m_set_bag == 0)
        return;
    if (!m_set_bag->has(x))
        m_set_bag->insert(x);
}

void set::insert(int *array, int x)
{
    if (m_set_bag == 0)
        return;
    int i = 0;

    while (i < x)
    {
        this->insert(array[i]);
        i++;
    }
}

void set::print() const
{
    if (m_set_bag == 0)
        return;
    this->m_set_bag->print();
}

void set::clear()
{
    if (m_set_bag == 0)
        return;
    this->m_set_bag->clear();
}
