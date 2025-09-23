
#include "searchable_tree_bag.hpp"

searchable_tree_bag::searchable_tree_bag() : tree_bag() {};

searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag &copy) : tree_bag(copy) {};

searchable_tree_bag &searchable_tree_bag::operator=(const searchable_tree_bag &other)
{
    if (this != &other)
    {
        tree_bag::operator=(other);
    }
    return *this;
}

bool searchable_tree_bag::has(int x) const
{
    node *cur = tree_;
    if (cur == 0)
        return false;

    while (cur)
    {
        if (cur->value == x)
            return true;

        if (cur->value < x)
            cur = cur->r;
        else
            cur = cur->l;
    }
    return false;
}
