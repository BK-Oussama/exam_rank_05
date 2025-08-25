
#include "searchable_tree_bag.hpp"

searchable_tree_bag::searchable_tree_bag() : tree_bag(){};

searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag &copy) : tree_bag(copy){};

searchable_tree_bag &searchable_tree_bag::operator=(const searchable_tree_bag &other)
{
    if (this != &other)
    {
        tree_bag::operator=(other);
    }
    return *this;
}

searchable_tree_bag::~searchable_tree_bag(){};

bool searchable_tree_bag::has(int x) const
{
    const node *cur = this->tree_;

    while (cur != 0)
    {
        if (x == cur->value)
            return true;

        if (x < cur->value)
            cur = cur->l;
        else
            cur = cur->r;
    }
    return false;
}