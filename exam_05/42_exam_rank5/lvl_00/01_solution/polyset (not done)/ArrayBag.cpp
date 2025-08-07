#include "ArrayBag.hpp"
#include <iostream>

ArrayBag::ArrayBag() : _data(NULL), _size(0) {}

ArrayBag::ArrayBag(const ArrayBag& other) : _data(NULL), _size(0) {
    if (other._size > 0) {
        _data = new int[other._size];
        _size = other._size;
        for (int i = 0; i < _size; i++)
            _data[i] = other._data[i];
    }
}

ArrayBag::~ArrayBag() {
    clear();
}

ArrayBag& ArrayBag::operator=(const ArrayBag& other) {
    if (this != &other) {
        clear();
        if (other._size > 0) {
            _data = new int[other._size];
            _size = other._size;
            for (int i = 0; i < _size; i++)
                _data[i] = other._data[i];
        }
    }
    return *this;
}

void ArrayBag::insert(int value) {
    int* newData = new int[_size + 1];
    for (int i = 0; i < _size; i++)
        newData[i] = _data[i];
    newData[_size] = value;
    delete[] _data;
    _data = newData;
    _size++;
}

void ArrayBag::insert(int* array, int arraySize) {
    for (int i = 0; i < arraySize; i++)
        insert(array[i]);
}

void ArrayBag::print() const {
    for (int i = 0; i < _size; i++)
        std::cout << _data[i] << " ";
    std::cout << std::endl;
}

void ArrayBag::clear() {
    delete[] _data;
    _data = NULL;
    _size = 0;
}