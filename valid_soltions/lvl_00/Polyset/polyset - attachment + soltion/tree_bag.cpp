#include "tree_bag.hpp"
#include <iostream>

tree_bag::tree_bag() : tree_(NULL)
{
}

tree_bag::tree_bag(const tree_bag &other) : tree_(NULL)
{
    tree_ = copy_node(other.tree_);
}

tree_bag &tree_bag::operator=(const tree_bag &other)
{
    if (this != &other)
    {
        clear();
        tree_ = copy_node(other.tree_);
    }
    return *this;
}

tree_bag::~tree_bag()
{
    clear();
}

void tree_bag::insert(int x)
{
    if (tree_ == NULL)
    {
        tree_ = new node;
        tree_->l = NULL;
        tree_->r = NULL;
        tree_->value = x;
        return;
    }
    node *cur = tree_;
    while (true)
    {
        if (x < cur->value)
        {
            if (cur->l == NULL)
            {
                node *n = new node;
                n->l = NULL;
                n->r = NULL;
                n->value = x;
                cur->l = n;
                return;
            }
            else
            {
                cur = cur->l;
            }
        }
        else
        {
            // duplicates go to the right (bag allows duplicates)
            if (cur->r == NULL)
            {
                node *n = new node;
                n->l = NULL;
                n->r = NULL;
                n->value = x;
                cur->r = n;
                return;
            }
            else
            {
                cur = cur->r;
            }
        }
    }
}

void tree_bag::insert(int *arr, int n)
{
    if (arr == NULL)
    {
        return;
    }
    if (n <= 0)
    {
        return;
    }
    for (int i = 0; i < n; i++)
    {
        insert(arr[i]);
    }
}

void tree_bag::print() const
{
    print_node(tree_);
    std::cout << std::endl;
}

void tree_bag::clear()
{
    destroy_tree(tree_);
    tree_ = NULL;
}

void tree_bag::destroy_tree(node *n)
{
    if (n == NULL)
    {
        return;
    }
    destroy_tree(n->l);
    destroy_tree(n->r);
    delete n;
}

void tree_bag::print_node(const node *n)
{
    if (n == NULL)
    {
        return;
    }
    print_node(n->l);
    std::cout << n->value << " ";
    print_node(n->r);
}

tree_bag::node *tree_bag::copy_node(const node *n)
{
    if (n == NULL)
    {
        return NULL;
    }
    node *m = new node;
    m->value = n->value;
    m->l = copy_node(n->l);
    m->r = copy_node(n->r);
    return m;
}
