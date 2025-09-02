#include "set.hpp"

set::set() : bag_(0) {};

set::set(searchable_bag &backend) : bag_(&backend) {};

set::set(const set &copy) : bag_(copy.bag_) {};

set &set::operator=(const set &other)
{
    if (this != &other)
    {
        this->bag_ = other.bag_;
    }

    return *this;
}

set::~set() {};

bool set::has(int x) const
{
    if (this->bag_ == 0)
        return false;

    return this->bag_->has(x);
};

void set::insert(int x)
{
    if (this->bag_ == 0)
        return;

    if (!this->bag_->has(x))
        this->bag_->insert(x);
};

void set::insert(int *array, int n)
{
    if (this->bag_ == 0 || n <= 0 || array == 0)
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
    if (this->bag_ == 0)
        return;
    this->bag_->print();
}

void set::clear()
{
    if (this->bag_ == 0)
        return;
    this->bag_->clear();
}