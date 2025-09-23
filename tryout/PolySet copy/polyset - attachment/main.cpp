#include "set.hpp"
#include "searchable_array_bag.hpp"
#include "searchable_tree_bag.hpp"
#include <iostream>

int main() {
    std::cout << "[SET — array backend via reference-ctor]" << std::endl;

    searchable_array_bag ab;
    set s_arr(ab); // uses set(const searchable_bag&)

    // Insert with duplicates; set should suppress
    s_arr.insert(1);
    s_arr.insert(1);
    s_arr.insert(2);
    s_arr.insert(2);
    s_arr.insert(3);

    std::cout << "arr_has_1: ";
    if (s_arr.has(1)) { std::cout << "true"; } else { std::cout << "false"; }
    std::cout << " | true" << std::endl;

    std::cout << "arr_has_2: ";
    if (s_arr.has(2)) { std::cout << "true"; } else { std::cout << "false"; }
    std::cout << " | true" << std::endl;

    std::cout << "arr_has_3: ";
    if (s_arr.has(3)) { std::cout << "true"; } else { std::cout << "false"; }
    std::cout << " | true" << std::endl;

    std::cout << "arr_has_9: ";
    if (s_arr.has(9)) { std::cout << "true"; } else { std::cout << "false"; }
    std::cout << " | false" << std::endl;

    std::cout << "arr_print (no duplicates expected):" << std::endl;
    s_arr.print();

    // Clear must forward
    s_arr.clear();
    std::cout << "arr_after_clear_has_1: ";
    if (s_arr.has(1)) { std::cout << "true"; } else { std::cout << "false"; }
    std::cout << " | false" << std::endl;


    std::cout << "\n[SET — tree backend via reference-ctor]" << std::endl;

    searchable_tree_bag tb;
    set s_tree(tb); // uses set(const searchable_bag&)

    // Batch insert with duplicates; set should suppress within the batch
    int vals[8];
    vals[0] = 5; vals[1] = 3; vals[2] = 7; vals[3] = 3;
    vals[4] = 8; vals[5] = 7; vals[6] = 9; vals[7] = 5;
    s_tree.insert(vals, 8);

    std::cout << "tree_has_3: ";
    if (s_tree.has(3)) { std::cout << "true"; } else { std::cout << "false"; }
    std::cout << " | true" << std::endl;

    std::cout << "tree_has_5: ";
    if (s_tree.has(5)) { std::cout << "true"; } else { std::cout << "false"; }
    std::cout << " | true" << std::endl;

    std::cout << "tree_has_7: ";
    if (s_tree.has(7)) { std::cout << "true"; } else { std::cout << "false"; }
    std::cout << " | true" << std::endl;

    std::cout << "tree_has_8: ";
    if (s_tree.has(8)) { std::cout << "true"; } else { std::cout << "false"; }
    std::cout << " | true" << std::endl;

    std::cout << "tree_has_42: ";
    if (s_tree.has(42)) { std::cout << "true"; } else { std::cout << "false"; }
    std::cout << " | false" << std::endl;

    std::cout << "tree_print (no duplicates expected):" << std::endl;
    s_tree.print();


    std::cout << "\n[SET — copy constructor shares backend]" << std::endl;

    set s_copy(s_tree); // copy-ctor; non-owning, shallow
    std::cout << "copy_has_5_before_insert_99: ";
    if (s_copy.has(5)) { std::cout << "true"; } else { std::cout << "false"; }
    std::cout << " | true" << std::endl;

    // Insert through the copy; should affect the same backend
    s_copy.insert(99);

    std::cout << "tree_has_99_after_copy_insert: ";
    if (s_tree.has(99)) { std::cout << "true"; } else { std::cout << "false"; }
    std::cout << " | true" << std::endl;

    std::cout << "copy_has_99_after_copy_insert: ";
    if (s_copy.has(99)) { std::cout << "true"; } else { std::cout << "false"; }
    std::cout << " | true" << std::endl;


    std::cout << "\n[SET — copy assignment shares backend]" << std::endl;

    // Rebuild array backend with some data
    searchable_array_bag ab2;
    set s_arr2(ab2);
    int a2vals[5];
    a2vals[0] = -1; a2vals[1] = 0; a2vals[2] = 10; a2vals[3] = 10; a2vals[4] = 11;
    s_arr2.insert(a2vals, 5);

    set s_assign;   // default-constructed (no backend)
    s_assign = s_arr2; // copy-assign; shallow handle copy

    // Insert via s_assign; should hit ab2 through s_arr2 as well
    s_assign.insert(42);

    std::cout << "arr2_has_42_after_assign_insert: ";
    if (s_arr2.has(42)) { std::cout << "true"; } else { std::cout << "false"; }
    std::cout << " | true" << std::endl;

    std::cout << "assign_has_42_after_assign_insert: ";
    if (s_assign.has(42)) { std::cout << "true"; } else { std::cout << "false"; }
    std::cout << " | true" << std::endl;


    std::cout << "\n[SET — default-constructed (no backend) is safely guarded]" << std::endl;

    set s_null; // no backend
    std::cout << "null_has_5: ";
    if (s_null.has(5)) { std::cout << "true"; } else { std::cout << "false"; }
    std::cout << " | false" << std::endl;

    s_null.insert(5);        // should be a no-op
    s_null.insert(vals, 8);  // should be a no-op
    s_null.clear();          // no-op
    std::cout << "null_print (should print nothing):" << std::endl;
    s_null.print();          // no output expected

    // Final clear checks on live sets
    s_tree.clear();
    std::cout << "tree_after_clear_has_5: ";
    if (s_tree.has(5)) { std::cout << "true"; } else { std::cout << "false"; }
    std::cout << " | false" << std::endl;

    s_arr2.clear();
    std::cout << "arr2_after_clear_has_-1: ";
    if (s_arr2.has(-1)) { std::cout << "true"; } else { std::cout << "false"; }
    std::cout << " | false" << std::endl;

    return 0;
}
