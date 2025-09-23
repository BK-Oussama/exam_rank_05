#include "array_bag.hpp"
#include <iostream>

array_bag::array_bag() : data_(NULL), size_(0)
{
}

array_bag::array_bag(const array_bag &other) : data_(NULL), size_(0)
{
    if (other.size_ > 0)
    {
        data_ = new int[other.size_];
        size_ = other.size_;
        for (int i = 0; i < size_; i++)
        {
            data_[i] = other.data_[i];
        }
    }
}

array_bag &array_bag::operator=(const array_bag &other)
{
    if (this != &other)
    {
        clear();
        if (other.size_ > 0)
        {
            data_ = new int[other.size_];
            size_ = other.size_;
            for (int i = 0; i < size_; i++)
            {
                data_[i] = other.data_[i];
            }
        }
        else
        {
            data_ = NULL;
            size_ = 0;
        }
    }
    return *this;
}

array_bag::~array_bag()
{
    clear();
}

void array_bag::insert(int x)
{
    int *new_data = new int[size_ + 1];
    for (int i = 0; i < size_; i++)
    {
        new_data[i] = data_[i];
    }
    new_data[size_] = x;
    delete[] data_;
    data_ = new_data;
    size_ = size_ + 1;
}

void array_bag::insert(int *arr, int n)
{
    if (arr == NULL)
    {
        return;
    }
    if (n <= 0)
    {
        return;
    }
    for (int i = 0; i < n; i++)
    {
        insert(arr[i]);
    }
}

void array_bag::print() const
{
    for (int i = 0; i < size_; i++)
    {
        std::cout << data_[i];
        if (i + 1 < size_)
        {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}

void array_bag::clear()
{
    if (data_ != NULL)
    {
        delete[] data_;
    }
    data_ = NULL;
    size_ = 0;
}

int array_bag::size() const
{
    return size_;
}
