#pragma once

#include <iostream>
#include <utility>

using namespace std;

class vect2{
	public:
		vect2();
		vect2(int, int);
		vect2(const vect2&);
		vect2& operator=(const vect2&);

		int operator[](int) const;
		int& operator[](int);

		vect2&	operator++();
		vect2 	operator++(int);
		vect2& 	operator--();
		vect2 	operator--(int);

		vect2& 	operator+=(const vect2&);
		vect2 	operator+(const vect2&) const;
		vect2& 	operator-=(const vect2&);
		vect2 	operator-(const vect2&) const;
		vect2  	operator*(int) const;
		vect2& 	operator*=(int);

		vect2 	operator-() const;

		bool	operator==(const vect2&);
		bool	operator!=(const vect2&);

	private:
		pair<int,int> p;
} ;

ostream& operator<<(ostream& out, const vect2& vec);
vect2 operator*(int, const vect2&);