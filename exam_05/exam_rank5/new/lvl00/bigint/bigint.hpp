#pragma once

#include <iostream>
#include <vector>

using namespace std;
using bigV = vector<int>;

class bigint{
	public:
		bigint();
		bigint(const bigint&);
		bigint(unsigned long long);
		~bigint();

		string getBig() const;

		bigint& operator+=(const bigint&);
		bigint 	operator+(const bigint&)const;

		bigint& operator++();
		bigint operator++(int);

		bigint 	operator<<(unsigned int)const;
		bigint& operator>>=(const bigint &);
		bigint& operator<<=(unsigned int);

		bool 	operator>=(const bigint&)const;
		bool 	operator>(const bigint&)const;
		bool 	operator<(const bigint&)const;
		bool 	operator==(const bigint&)const;
		bool 	operator!=(const bigint&)const;
		bool 	operator<=(const bigint&)const;
	
	private:
		bigV big;
} ;
	ostream & operator<<(ostream& out, const bigint &);
