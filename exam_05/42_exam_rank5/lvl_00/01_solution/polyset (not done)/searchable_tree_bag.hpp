#ifndef SEARCHABLE_TREE_BAG_HPP
#define SEARCHABLE_TREE_BAG_HPP

#include "TreeBag.hpp"
#include "SearchableBag.hpp"

class SearchableTreeBag : public TreeBag, public SearchableBag {
public:
    SearchableTreeBag();
    SearchableTreeBag(const SearchableTreeBag& other);
    ~SearchableTreeBag();
    SearchableTreeBag& operator=(const SearchableTreeBag& other);

    virtual bool has(int value) const;
};

#endif