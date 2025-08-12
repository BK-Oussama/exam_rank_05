#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>
#include <string>
#include <cctype>
#include <ostream>
#include <sstream>

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
    bigint &operator=(const bigint &);

    const std::string &get_value() const;
};

std::ostream &operator<<(std::ostream &out, const bigint &num);


bool operator==(const bigint &a, const bigint &b);
bool operator!=(const bigint &a, const bigint &b);
bool operator<(const bigint &a, const bigint &b);
bool operator<=(const bigint &a, const bigint &b);
bool operator>(const bigint &a, const bigint &b);
bool operator>=(const bigint &a, const bigint &b);



#endif