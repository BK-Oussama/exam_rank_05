#ifndef BB438612_20AD_4DA8_ACE7_F06576392A6D
#define BB438612_20AD_4DA8_ACE7_F06576392A6D
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


#endif /* BB438612_20AD_4DA8_ACE7_F06576392A6D */
