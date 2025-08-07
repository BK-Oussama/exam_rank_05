#include "searchable_tree_bag.hpp"
#include "searchable_array_bag.hpp"
#include "Set.hpp"
#include <iostream>
#include <climits>

void testBasicOperations(SearchableBag* bag) {
    std::cout << "\n=== Testing Basic Operations ===" << std::endl;
    
    // Test single insertions
    bag->insert(1);
    bag->insert(2);
    bag->insert(3);
    std::cout << "After inserting 1,2,3: ";
    bag->print();

    // Test array insertion
    int arr[] = {4, 5, 6};
    bag->insert(arr, 3);
    std::cout << "After inserting array {4,5,6}: ";
    bag->print();

    // Test search
    std::cout << "Has 3? " << (bag->has(3) ? "yes" : "no") << std::endl;
    std::cout << "Has 7? " << (bag->has(7) ? "yes" : "no") << std::endl;

    // Test clear
    std::cout << "Before clear: ";
    bag->print();
    bag->clear();
    std::cout << "After clear: ";
    bag->print();
}

void testSetOperations(SearchableBag* bag) {
    std::cout << "\n=== Testing Set Operations ===" << std::endl;
    
    Set set(bag);
    
    // Test duplicate insertions
    set.insert(1);
    set.insert(1);
    set.insert(1);
    std::cout << "After inserting 1 three times: ";
    set.print();

    // Test array with duplicates
    int arr[] = {1, 2, 2, 3, 3, 3};
    set.insert(arr, 6);
    std::cout << "After inserting array with duplicates: ";
    set.print();

    // Test search
    std::cout << "Has 2? " << (set.has(2) ? "yes" : "no") << std::endl;
    std::cout << "Has 4? " << (set.has(4) ? "yes" : "no") << std::endl;

    // Test clear
    std::cout << "Before clear: ";
    set.print();
    set.clear();
    std::cout << "After clear: ";
    set.print();
}

void testEdgeCases(SearchableBag* bag) {
    std::cout << "\n=== Testing Edge Cases ===" << std::endl;
    
    Set set(bag);
    // Test empty array insertion
    int arr[] = {};
    std::cout << "Before clear: ";
    set.print();
    set.insert(arr, 0);
    std::cout << "After inserting empty array: ";
    set.print();

    // Test large numbers
    set.insert(INT_MAX);
    set.insert(INT_MIN);
    std::cout << "After inserting INT_MAX and INT_MIN: ";
    set.print();

    // Test searching in empty set
    set.clear();
    std::cout << "Has 0 in empty set? " << (set.has(0) ? "yes" : "no") << std::endl;
}

void testCopyOperations() {
    std::cout << "\n=== Testing Copy Operations ===" << std::endl;
    
    // Test ArrayBag copy
    SearchableArrayBag* arr1 = new SearchableArrayBag();
    arr1->insert(1);
    arr1->insert(2);
    
    SearchableArrayBag* arr2 = new SearchableArrayBag(*arr1);
    std::cout << "Original array: ";
    arr1->print();
    std::cout << "Copied array: ";
    arr2->print();

    // Test TreeBag copy
    SearchableTreeBag* tree1 = new SearchableTreeBag();
    tree1->insert(1);
    tree1->insert(2);
    
    SearchableTreeBag* tree2 = new SearchableTreeBag(*tree1);
    std::cout << "Original tree: ";
    tree1->print();
    std::cout << "Copied tree: ";
    tree2->print();

    delete arr1;
    delete arr2;
    delete tree1;
    delete tree2;
}

int main() {
    SearchableArrayBag* arrayBag = new SearchableArrayBag();
    SearchableTreeBag* treeBag = new SearchableTreeBag();

    std::cout << "Testing Array Implementation:" << std::endl;
    testBasicOperations(arrayBag);
    testSetOperations(arrayBag);
    testEdgeCases(arrayBag);

    std::cout << "\nTesting Tree Implementation:" << std::endl;
    testBasicOperations(treeBag);
    testSetOperations(treeBag);
    testEdgeCases(treeBag);

    testCopyOperations();

    // Memory cleanup
    delete arrayBag;
    delete treeBag;

    std::cout << "\nAll tests completed successfully!" << std::endl;
    return 0;
}