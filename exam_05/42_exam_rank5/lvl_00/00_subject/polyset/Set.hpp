#ifndef SET_HPP
#define SET_HPP

#include "SearchableBag.hpp"

class Set {
private:
    SearchableBag* bag;

public:
    Set(SearchableBag* bag);
    Set(const Set& other);
    virtual ~Set();
    Set& operator=(const Set& other);

    void insert(int value);
    void insert(int*, int);
    bool has(int value) const;
    void print() const;
    void clear();
};

#endif