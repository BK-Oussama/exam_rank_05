#ifndef VECT2_HPP
#define VECT2_HPP

#include <iostream>

class vect2{
    private:
    int x; //0
    int y; //1

    public:
    vect2(); // default constructor
    vect2(int x, int y); // init with coordinates
    vect2(const vect2& other); // copy constructor

    vect2& operator=(const vect2& other) throw(); //copy assignment operator

    // Arithmetic operators
	vect2 operator+(const vect2& other) const;
	vect2& operator+=(const vect2& other);

	vect2 operator-(const vect2& other) const;
	vect2& operator-=(const vect2& other);

	vect2 operator*(int scalar) const; // scalar multiplication
	vect2& operator*=(int scalar);
	
	// Unary operators
	vect2 operator-() const; // unary minus
	// Comparison operators
	bool operator==(const vect2& other) const;
	bool operator!=(const vect2& other) const;

	// Array access operator
	int& operator[](int index);
	const int& operator[](int index) const;

	// Increment/decrement operators
	vect2& operator++();    // prefix ++
	vect2 operator++(int);  // postfix ++
	vect2& operator--();    // prefix --
	vect2 operator--(int);  // postfix --

	// Friend for printing
	friend std::ostream& operator<<(std::ostream& os, const vect2& v);

    int getX() const throw();

    int getY() const throw();

    // void setX(int newX) throw();

    // void setY(int newY) throw();

	friend vect2 operator*(int scalar, const vect2& v);

};
// Scalar multiplication (left: int * vect2)
//vect2 operator*(int scalar, const vect2& v);

#endif