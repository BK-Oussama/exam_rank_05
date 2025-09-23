

#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <bits/stdc++.h>

class bigint
{
public:
    bigint();
    bigint(std::string num);
    bigint(unsigned long num);
    bigint (const bigint &copy);

    bigint &operator=(const bigint &other);
    bigint &operator+=(const bigint &other);

    std::string get_value() const;
    void trim();
    void check_digits();

    bigint &operator>>=(int k);
    bigint &operator<<=(int k);

    bigint &operator++();
    bigint operator++(int);


private:
    std::string m_value;
};

std::ostream &operator<<(std::ostream &os, const bigint &A);

bool operator==(const bigint &A, const bigint &B); 
bool operator!=(const bigint &A, const bigint &B);
bool operator>(const bigint &A, const bigint &B); 
bool operator>=(const bigint &A, const bigint &B); 
bool operator<(const bigint &A, const bigint &B); 
bool operator<=(const bigint &A, const bigint &B);

bigint operator+(const bigint &A, const bigint &B);

bigint operator>>(const bigint &A, int k);
bigint operator<<(const bigint &A, int k);




#endif