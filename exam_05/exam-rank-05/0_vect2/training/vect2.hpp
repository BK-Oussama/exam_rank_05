#ifndef VECT2_HPP
#define VECT2_HPP

#include <iostream>

class vect2 {
private:
	int x;
	int y;

public:
	vect2(); //default constructor
	vect2(int x, int y); // constructor w. values
	vect2(const vect2& other); // copy constructor
	vect2&	operator=(const vect2& other); //assignment
	
	
	//arithmetic
	vect2	operator+(const vect2& other) const;
	vect2&	operator+=(const vect2& other);
	
	vect2	operator-(const	vect2& other) const;
	vect2&	operator-=(const vect2& other);

	vect2	operator*(int scalar) const;
	vect2&	operator*=(int scalar);

	//unary
	vect2	operator-()const;

	//bool
	bool	operator==(const vect2& other) const;
	bool	operator!=(const vect2& other) const;

	//access
	int&	operator[](int index);
	const int&	operator[](int index) const;

	vect2&	operator++(); // prefix: ++x
	vect2	operator++(int); // postfix x++

	vect2&	operator--(); // prefix: --x
	vect2	operator--(int); // postfix x--

	friend std::ostream& operator<<(std::ostream& os, const vect2& v);
	friend vect2 operator*(int scalar, const vect2& v);

};

#endif
