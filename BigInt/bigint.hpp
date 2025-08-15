#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>
#include <string>
#include <cctype>
#include <ostream>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <cassert>

// know the use of each header file 

class bigint
{
private:
    std::string m_value;

    void trim();
    void check_digits();

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