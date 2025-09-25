#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <bits/stdc++.h>


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

    //  The compiler distinguishes between prefix and postfix by using a dummy int; postfix uses the dummy int.

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