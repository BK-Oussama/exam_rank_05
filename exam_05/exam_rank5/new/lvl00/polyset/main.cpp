#include "searchable_bag.hpp"

// new code
#include "mine/searchable_tree_bag.hpp"
#include "mine/searchable_array_bag.hpp"
#include "mine/set.hpp"
//end new code

#include <iostream>

int main(int argc, char **argv) {
  if (argc == 1)
    return 1;
  searchable_bag *t = new searchable_tree_bag;
  searchable_bag *a = new searchable_array_bag;

  for (int i = 1; i < argc; i++) {
    std::cout << argv[i] << std::endl;
    t->insert(atoi(argv[i]));
    a->insert(atoi(argv[i]));
  }
  t->print();
  a->print();

  for (int i = 1; i < argc; i++) {
    std::cout << t->has(atoi(argv[i])) << std::endl;
    std::cout << a->has(atoi(argv[i])) << std::endl;
    std::cout << t->has(atoi(argv[i]) - 1) << std::endl;
    std::cout << a->has(atoi(argv[i]) - 1) << std::endl;
  }

  t->clear();
  a->clear();

  const searchable_array_bag tmp(static_cast<searchable_array_bag &>(*a));
  tmp.print();
  tmp.has(1);

  set sa(*a);
  set st(*t);
  for (int i = 1; i < argc; i++) {
    st.insert(atoi(argv[i]));
    sa.insert(atoi(argv[i]));

    sa.has(atoi(argv[i]));
    sa.print();
    sa.get_bag().print();
    st.print();
    sa.clear();
    int arr[] = {
            1,
            2,
            3,
            4,
        };
    sa.insert(
        arr,
        4);
    std::cout << std::endl;
		std::cout << "extra tests for set " << std::endl;
    // searchable_bag *
    a->clear();
    set test_s(*a);
    test_s.insert(99);
    test_s.insert(arr, 4);
    test_s.insert(99);
    test_s.print();
    test_s.get_bag().print();
  }

  return 0;
}