#include "bigint.hpp"

bigint::bigint() : digits("0") {}

bigint::bigint(unsigned int n) {
	if (n == 0)
        digits = "0";
	while (n > 0) {
		digits += '0' + (n % 10);
		n /= 10;
	}
}

bigint::bigint(const bigint& other) : digits(other.digits) {}

bigint& bigint::operator=(const bigint& other){
	if(this != &other)
	{
		this->digits = other.digits;
	}
	return *this;
}


bigint bigint::operator+(const bigint& other) const {
	bigint res;
	res.digits.clear();
	int carry = 0;
	size_t i = 0;
	while (i < digits.size() || i < other.digits.size() || carry) {

        // "if a digit exists at position i, use it - otherwise consider that digit as 0"
		int d1 = (i < digits.size()) ? digits[i] - '0' : 0;
		int d2 = (i < other.digits.size()) ? other.digits[i] - '0' : 0;

		int sum = d1 + d2 + carry;
		res.digits += '0' + (sum % 10);
		carry = sum / 10;
		++i;
	}
	return res;
}

bigint& bigint::operator+=(const bigint& other) {
	*this = *this + other;
	return *this;
}

bigint bigint::operator<<(unsigned int n) const {
	if (digits == "0") { return bigint(0); }
	bigint res = *this;
	res.digits.insert(0, n, '0');
	return res;
}

bigint& bigint::operator<<=(unsigned int n) {
	if (digits == "0") { return *this; }
	digits.insert(0, n, '0');
	return *this;
}

bigint bigint::operator>>(unsigned int n) const {
	bigint res = *this;
	res.digits = (n >= res.digits.size()) ? "0" : res.digits.substr(n);
	return res;
}

bigint& bigint::operator>>=(unsigned int n) {
	digits = (n >= digits.size()) ? "0" : digits.substr(n);
	return *this;
}

bigint& bigint::operator++() {
	return *this += bigint(1);
}

bigint bigint::operator++(int) {
	bigint tmp = *this;
	++(*this);
	return tmp;
}

bool bigint::operator==(const bigint& other) const { 
    return digits == other.digits;
}
bool bigint::operator!=(const bigint& other) const {
    return !(*this == other);
}

bool bigint::operator<(const bigint& other) const {
	if (digits.size() != other.digits.size())
		return digits.size() < other.digits.size();
	for (int i = digits.size() - 1; i >= 0; --i)
		if (digits[i] != other.digits[i])
			return digits[i] < other.digits[i];
	return false;
}
bool bigint::operator>(const bigint& other) const { 
    return other < *this;
}
bool bigint::operator<=(const bigint& other) const {
    return !(other < *this);
}
bool bigint::operator>=(const bigint& other) const { 
    return !(other > *this);
}

// dummy implementation for subtraction
bigint bigint::operator-(const bigint& other) const {
	if (*this == other)
        return bigint(0);
	return bigint(0); 
}

std::ostream& operator<<(std::ostream& os, const bigint& n) {
	for (std::string::const_reverse_iterator it = n.digits.rbegin(); it != n.digits.rend(); ++it)
		os << *it;
	return os;
}
