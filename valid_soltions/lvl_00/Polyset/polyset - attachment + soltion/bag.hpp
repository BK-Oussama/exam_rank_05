#ifndef BAG_HPP
#define BAG_HPP

class bag
{
public:
    virtual ~bag() {}
    virtual void insert(int x) = 0;
    virtual void insert(int *array, int n) = 0;
    virtual void print() const = 0;
    virtual void clear() = 0;
};

#endif
