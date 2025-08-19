#ifndef VECT2_HPP
#define VECT2_HPP

#include <iostream>

class vect2
{
public:
    vect2();
    vect2(int x, int y);
    vect2(const vect2 &copy);
    ~vect2();

    vect2 &operator=(const vect2 &other);
    vect2 &operator+=(const vect2 &other);
    vect2 &operator-=(const vect2 &other);
    vect2 &operator*=(const int scalar);

    vect2 operator+() const;
    vect2 operator-() const;

    vect2 &operator++();
    vect2 operator++(int);

    vect2 &operator--();
    vect2 operator--(int);

    bool operator==(const vect2 &other) const;
    bool operator!=(const vect2 &other) const;

    int &operator[](int i);
    const int &operator[](int i) const;

    vect2 operator+(const vect2 &other) const;
    vect2 operator-(const vect2 &other) const;
    vect2 operator*(const int scaler) const;

    friend std::ostream &operator<<(std::ostream &os, const vect2 &v);

private:
    int m_x;
    int m_y;
};

vect2 operator*(const int scaler, const vect2 &other);

#endif