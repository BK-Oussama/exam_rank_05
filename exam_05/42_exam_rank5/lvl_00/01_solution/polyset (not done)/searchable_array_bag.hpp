#ifndef SEARCHABLE_ARRAY_BAG_HPP
#define SEARCHABLE_ARRAY_BAG_HPP

#include "ArrayBag.hpp"
#include "SearchableBag.hpp"

class SearchableArrayBag : public ArrayBag, public SearchableBag {
public:
    SearchableArrayBag();
    SearchableArrayBag(const SearchableArrayBag& other);
    ~SearchableArrayBag();
    SearchableArrayBag& operator=(const SearchableArrayBag& other);

    virtual bool has(int value) const;
};

#endif