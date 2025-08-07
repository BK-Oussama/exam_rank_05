#include "vect2.hpp"

vect2::vect2(): x(0), y(0) {}

vect2::vect2(int x, int y) : x(x), y(y) {}

vect2::vect2(const vect2& other) : x(other.x), y(other.y){}

// Assignment operator
vect2& vect2::operator=(const vect2& other)throw() {
    if (this != &other){
        x = other.x;
        y = other.y;
    }
    return *this;
}

// Output operator
std::ostream& operator<<(std::ostream& os, const vect2& v) {
	os << "{" << v.x << ", " << v.y << "}";
	return os;
}

// Addition
vect2 vect2::operator+(const vect2& other) const {
	return vect2(x + other.x, y + other.y);
}

vect2& vect2::operator+=(const vect2& other) {
	x += other.x;
	y += other.y;
	return *this;
}

// Subtraction
vect2 vect2::operator-(const vect2& other) const {
	return vect2(x - other.x, y - other.y);
}

vect2& vect2::operator-=(const vect2& other) {
	x -= other.x;
	y -= other.y;
	return *this;
}

// Equality
bool vect2::operator==(const vect2& other) const {
	return x == other.x && y == other.y;
}

bool vect2::operator!=(const vect2& other) const {
	return !(*this == other);
}

// Prefix increment (++v)
vect2& vect2::operator++() {
	++x;
	++y;
	return *this;
}

// Postfix increment (v++)
vect2 vect2::operator++(int) {
	vect2 temp(*this);
	++(*this);
	return temp;
}

// Prefix decrement (--v)
vect2& vect2::operator--() {
	--x;
	--y;
	return *this;
}

// Postfix decrement (v--)
vect2 vect2::operator--(int) {
	vect2 temp(*this);
	--(*this);
	return temp;
}

vect2 operator*(int scalar, const vect2& v) {
	return vect2(v.getX() * scalar, v.getY() * scalar);
}

int vect2::getX() const throw() {
	return x;
}

int vect2::getY() const throw() {
	return y;
}

// void vect2::setX(int newX) throw() {
// 	x = newX;
// }

// void vect2::setY(int newY) throw() {
// 	y = newY;
// }


// * operator
vect2 vect2::operator*(int scalar) const{
	return vect2(x * scalar, y * scalar);
}

vect2& vect2::operator*=(int scalar){
	x *= scalar;
	y *= scalar;
	return *this;
}

// Array access operator
int& vect2::operator[](int index) {
	if (index == 0)
		return x;
	else
		return y;  // index == 1
}

const int& vect2::operator[](int index) const {
	if (index == 0)
		return x;
	else
		return y;  // index == 1
}

// Unary minus operator
vect2 vect2::operator-() const {
	return vect2(-x, -y);
}