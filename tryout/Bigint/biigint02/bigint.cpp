
#include "bigint.hpp"

bigint::bigint() : m_value("0") {};

bigint::bigint(unsigned long num)
{
    std::ostringstream buffer;
    buffer << num;
    m_value = buffer.str();
};

bigint::bigint(std::string num) : m_value(num)
{
    trim();
    check_digits();
}

void bigint::trim()
{
    size_t pos = m_value.find_first_not_of("0");

    if (pos == std::string::npos)
    {
        m_value = "0";
        return;
    }
    m_value = m_value.substr(pos);
}

void bigint::check_digits()
{
    std::string num = get_value();

    if (num.empty())
        m_value = "0";

    size_t i = 0;

    while (i < num.size())
    {
        if (std::isdigit(num[i]) == 0)
            m_value = "0";
        i++;
    }
}

std::string bigint::get_value() const
{
    return m_value;
}

bigint::bigint(const bigint &copy) : m_value(copy.m_value) {};

bigint &bigint::operator=(const bigint &other)
{
    if (this != &other)
        m_value = other.m_value;
    return *this;
}

bigint &bigint::operator+=(const bigint &other)
{
    *this = *this + other;
    return *this;
}

std::ostream &operator<<(std::ostream &os, const bigint &A)
{
    os << A.get_value();
    return os;
}

bool operator==(const bigint &A, const bigint &B)
{
    if (A.get_value() == B.get_value())
        return true;
    return false;
}

bool operator!=(const bigint &A, const bigint &B)
{
    if (A == B)
        return false;
    return true;
}

int compare_string(std::string A, std::string B)
{
    if (A.size() < B.size())
        return -1;
    if (A.size() > B.size())
        return 1;

    if (A == B)
        return 0;

    if (A < B)
        return -1;
    if (A > B)
        return 1;
    return 0;
}

bool operator>(const bigint &A, const bigint &B)
{
    int cmp = compare_string(A.get_value(), B.get_value());

    if (cmp > 0)
        return true;
    return false;
}

bool operator>=(const bigint &A, const bigint &B)
{
    int cmp = compare_string(A.get_value(), B.get_value());
    if (cmp >= 0)
        return true;
    return false;
}

bool operator<(const bigint &A, const bigint &B)
{
    int cmp = compare_string(A.get_value(), B.get_value());
    if (cmp < 0)
        return true;
    return false;
}

bool operator<=(const bigint &A, const bigint &B)
{
    int cmp = compare_string(A.get_value(), B.get_value());
    if (cmp <= 0)
        return true;
    return false;
}

bigint operator+(const bigint &A, const bigint &B)
{
    std::string a = A.get_value();
    std::string b = B.get_value();

    std::string result;

    int i = (int)a.size() - 1;
    int j = (int)b.size() - 1;
    int carry = 0;

    while (i >= 0 || j >= 0 || carry > 0)
    {
        int digit_a = 0;
        if (i >= 0)
            digit_a = a[i] - '0';

        int digit_b = 0;
        if (j >= 0)
            digit_b = b[j] - '0';

        int sum = digit_a + digit_b + carry;

        int dig_out = sum % 10;
        carry = sum / 10;
        result.push_back(dig_out + '0');
        j--;
        i--;
    }
    std::reverse(result.begin(), result.end());

    return bigint(result);
}

bigint operator>>(const bigint &A, int k)
{
    std::string res = A.get_value();

    if (k <= 0)
        return A;

    int s = res.size();
    if (k >= s)
        return bigint("0");
    res.erase(s - k);
    return bigint(res);
}

bigint operator<<(const bigint &A, int k)
{
    if (k <= 0)
        return A;
    std::string res = A.get_value();
    if (res == "0")
        return A;

    res.append(k, '0');
    return (bigint(res));
}

bigint &bigint::operator>>=(int k)
{
    *this = *this >> k;
    return *this;
}

bigint &bigint::operator<<=(int k)
{
    *this = *this << k;
    return *this;
}

bigint &bigint::operator++()
{
    *this = *this + bigint(1);
    return *this;
}


bigint bigint::operator++(int)
{
    bigint old = *this;
    *this = *this + bigint(1);
    return old;
}