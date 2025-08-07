#include <iostream>
#include "searchable_array_bag.hpp"
#include "searchable_tree_bag.hpp"
#include "set.hpp"

int main()
{
    std::cout << "--- searchable_array_bag ---" << std::endl;
    searchable_array_bag arr_bag;
    arr_bag.insert(1);
    arr_bag.insert(2);
    arr_bag.insert(3);
    arr_bag.insert(2); // duplicate
    std::cout << "Search 2: " << arr_bag.search(2) << std::endl;
    std::cout << "Search 5: " << arr_bag.search(5) << std::endl;

    std::cout << "--- searchable_tree_bag ---" << std::endl;
    searchable_tree_bag tree_bag;
    tree_bag.insert(10);
    tree_bag.insert(5);
    tree_bag.insert(20);
    tree_bag.insert(10); // duplicate
    std::cout << "Search 10: " << tree_bag.search(10) << std::endl;
    std::cout << "Search 30: " << tree_bag.search(30) << std::endl;

    std::cout << "--- set using array_bag ---" << std::endl;
    set set1(&arr_bag);
    set1.insert(1);
    set1.insert(1); // should not insert again
    set1.insert(4);
    std::cout << "Search 1: " << set1.search(1) << std::endl;
    std::cout << "Search 4: " << set1.search(4) << std::endl;
    std::cout << "Search 5: " << set1.search(5) << std::endl;

    std::cout << "--- set using tree_bag ---" << std::endl;
    set set2(&tree_bag);
    set2.insert(10);
    set2.insert(20);
    set2.insert(10); // duplicate
    std::cout << "Search 10: " << set2.search(10) << std::endl;
    std::cout << "Search 15: " << set2.search(15) << std::endl;

    return 0;
}
