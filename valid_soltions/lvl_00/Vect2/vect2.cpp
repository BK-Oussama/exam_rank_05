
#include "vect2.hpp"

vect2::vect2() : m_x(0), m_y(0) {};

vect2::vect2(int x, int y) : m_x(x), m_y(y) {};

vect2::vect2(const vect2 &copy) : m_x(copy.m_x), m_y(copy.m_y) {};

vect2::~vect2() {};

vect2 &vect2::operator=(const vect2 &other)
{
    if (this != &other)
    {
        m_x = other.m_x;
        m_y = other.m_y;
    }
    return *this;
}

bool vect2::operator==(const vect2 &other) const
{
    if (this->m_x == other.m_x && this->m_y == other.m_y)
        return true;
    return false;
}

bool vect2::operator!=(const vect2 &other) const
{
    if (*this == other)
        return false;
    return true;
}

std::ostream &operator<<(std::ostream &os, const vect2 &v)
{
    os << "{" << v.m_x << ", " << v.m_y << "}";
    return os;
}

int &vect2::operator[](int i)
{
    if (i == 0)
        return m_x;
    else if (i == 1)
        return m_y;
    else
        throw std::out_of_range("out of bound vect2");
}

const int &vect2::operator[](int i) const
{
    if (i == 0)
        return m_x;
    else if (i == 1)
        return m_y;
    else
        throw std::out_of_range("out of bound vect2");
}

vect2 vect2::operator+(const vect2 &other) const
{
    int x = this->m_x + other.m_x;
    int y = this->m_y + other.m_y;

    return (vect2(x, y));
}

vect2 vect2::operator-(const vect2 &other) const
{
    int x = this->m_x - other.m_x;
    int y = this->m_y - other.m_y;

    return (vect2(x, y));
}

vect2 vect2::operator*(const int scalar) const
{
    int x = this->m_x * scalar;
    int y = this->m_y * scalar;

    return vect2(x, y);
}

vect2 operator*(const int scalar, const vect2 &other)
{
    return (other * scalar);
}

vect2 &vect2::operator+=(const vect2 &other)
{
    *this = *this + other;
    return *this;
}

vect2 &vect2::operator-=(const vect2 &other)
{
    *this = *this - other;
    return *this;
}

vect2 &vect2::operator*=(const int scalar)
{
    *this = *this * scalar;
    return *this;
}

vect2 vect2::operator+() const
{
    return *this;
}

vect2 vect2::operator-() const
{
    return vect2(-m_x, -m_y);
}

vect2 &vect2::operator++()
{
    m_x++;
    m_y++;
    return *this;
}

vect2 vect2::operator++(int)
{
    vect2 old = *this;
    m_x++;
    m_y++;
    return old;
}

vect2 &vect2::operator--()
{
    m_x--;
    m_y--;

    return *this;
}

vect2 vect2::operator--(int)
{
    vect2 old = *this;
    m_x--;
    m_y--;
    return old;
}