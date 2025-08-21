#pragma once

#include "bag.hpp"

class tree_bag : virtual public bag {
protected:
  struct node {
    node *l;
    node *r;
    int value;
  };
  node *tree;

public:
  tree_bag();
  tree_bag(const tree_bag &);
  virtual ~tree_bag();
  tree_bag &operator=(const tree_bag &);

  node *extract_tree();
  void set_tree(node *);

  virtual void insert(int);
  virtual void insert(int *array, int size);
  virtual void print() const;
  virtual void clear();

//static functions will operate on the tree
private:
// pass a node and destroy the tree from that node
  static void destroy_tree(node *);
  // recursively print nodes from node passed
  static void print_node(node *);
  // recursively copy nodes from node passed
  static node *copy_node(node *);
};