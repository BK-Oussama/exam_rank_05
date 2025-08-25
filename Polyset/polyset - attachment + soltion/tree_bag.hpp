#ifndef TREE_BAG_HPP
#define TREE_BAG_HPP

#include "bag.hpp"

class tree_bag : virtual public bag
{
protected:
    struct node
    {
        node *l;
        node *r;
        int value;
    };
    node *tree_;

public:
    tree_bag();
    tree_bag(const tree_bag &other);
    tree_bag &operator=(const tree_bag &other);
    virtual ~tree_bag();

    virtual void insert(int x);
    virtual void insert(int *arr, int n);
    virtual void print() const;
    virtual void clear();

protected:
    static void destroy_tree(node *n);
    static void print_node(const node *n);
    static node *copy_node(const node *n);
};

#endif
