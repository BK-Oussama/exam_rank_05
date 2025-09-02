#ifndef BIGINT_HPP
#define BIGINT_HPP

// #include <iostream>
// #include <string>
// #include <cctype>
// #include <ostream>
// #include <sstream>
// #include <algorithm>
// #include <iostream>
// #include <cassert>

#include <bits/stdc++.h>

// know the use of each header file

class bigint
{
private:
    std::string m_value;

    void trim();
    void check_digits(); // in private put function that change the member data

public:
    bigint();
    bigint(unsigned int num);
    bigint(const std::string &num);

    bigint(const bigint &copy);
    ~bigint();

    bigint &operator=(const bigint &other);
    bigint &operator+=(const bigint &other);

    const std::string &get_value() const;

    bigint &operator<<=(int k);
    bigint &operator>>=(int k);

    //  The compiler distinguishes between prefix and postfix by using a dummy int; postfix uses the dummy int.
    //  Note that this means the return value of the overloaded operator must be a non-reference,
    //  because we can’t return a reference to a local variable that will be destroyed when the function exits.

    bigint &operator++();
    bigint operator++(int);
};

std::ostream &operator<<(std::ostream &out, const bigint &num);

int compare_string(const std::string &A, const std::string &B);

bool operator==(const bigint &a, const bigint &b);
bool operator!=(const bigint &a, const bigint &b);
bool operator<(const bigint &a, const bigint &b);
bool operator<=(const bigint &a, const bigint &b);
bool operator>(const bigint &a, const bigint &b);
bool operator>=(const bigint &a, const bigint &b);

bigint operator+(const bigint &a, const bigint &b);

bigint operator>>(const bigint &num, int k);
bigint operator<<(const bigint &num, int k);

#endif