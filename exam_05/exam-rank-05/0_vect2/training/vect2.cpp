#include "vect2.hpp"	

vect2::vect2(): x(0), y(0){} // constructor

vect2::vect2(int x, int y) : x(x), y(y){} // constructor w. values

vect2::vect2(const vect2& other): x(other.x), y(other.y){}

vect2&	vect2::operator=(const vect2& other){ //assignment
    if (this != &other){
        x = other.x;
        y = other.y;
    }
    return *this;
}
//arithmetic
vect2	vect2::operator+(const vect2& other) const{
    return vect2(x + other.x, y + other.y);
}

vect2&	vect2::operator+=(const vect2& other){
    x = x + other.x;
    y = y + other.y;
    return *this;
}
	
vect2	vect2::operator-(const	vect2& other) const{
    return vect2(x - other.x, y - other.y);
}
vect2&	vect2::operator-=(const vect2& other){
    x = x - other.x;
    y = y - other.y;
    return *this;
}

vect2	vect2::operator*(int scalar) const{
    return vect2(scalar * x, scalar * y);
}
vect2&	vect2::operator*=(int scalar){
    x = x * scalar;
    y = y * scalar;
    return *this;
}

//unary
vect2	vect2::operator-()const{
    return (-1 * *this);
}

//bool
bool	vect2::operator==(const vect2& other) const{
    return (x == other.x && y == other.y);
}
bool	vect2::operator!=(const vect2& other) const{
    return !(*this == other);
}

//access
int&	vect2::operator[](int index){
    //return (index == 0) ? x : y;
    if (index == 0)
        return x;
    else
        return y;
}
const int&	vect2::operator[](int index) const{
    if (index == 0)
        return x;
    else
        return y;
}

// prefix: ++x
vect2&	vect2::operator++(){
    ++x;
    ++y;
    return *this;
}

// postfix x++
vect2	vect2::operator++(int){
    vect2   tmp(*this);
    ++(*this);
    return tmp;
}

// prefix: --x
vect2&	vect2::operator--(){
    --x;
    --y;
    return *this;
}

// postfix x--
vect2	vect2::operator--(int){
    vect2   tmp(*this);
    --(*this);
    return tmp;
}

std::ostream& operator<<(std::ostream& os, const vect2& v){
    os << "{" << v.x << ", " << v.y << "}";
    return os;
}
vect2 operator*(int scalar, const vect2& v){
    return (v * scalar);
}