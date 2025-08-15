
#include "bigint.hpp"

bigint::bigint() : m_value("0") {}

bigint::bigint(unsigned int n)
{
    std::ostringstream buffer;
    buffer << n;
    m_value = buffer.str();
}

bigint::bigint(const std::string &num) : m_value(num)
{
    trim();
    check_digits();
}

bigint::bigint(const bigint &copy) : m_value(copy.m_value)
{
}

bigint::~bigint()
{
    std::cout << "Destructor called" << std::endl;
}

void bigint::trim()
{
    size_t pos = m_value.find_first_not_of('0');

    if (pos == std::string::npos)
        m_value = "0";
    else
        m_value = m_value.substr(pos);
}

void bigint::check_digits()
{
    if (m_value.empty())
        m_value = "0";

    size_t i = 0;
    while (i < m_value.size())
    {
        if (!std::isdigit(static_cast<unsigned char>(m_value[i])))
        {
            m_value = "0";
            return;
        }
        i++;
    }
}

const std::string &bigint::get_value() const
{
    return m_value;
}

std::ostream &operator<<(std::ostream &os, const bigint &num)
{
    os << num.get_value();
    return os;
}

int compare_string(const std::string &A, const std::string &B)
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

bool operator==(const bigint &a, const bigint &b)
{
    if (a.get_value() == b.get_value())
        return true;
    return false;
}

bool operator!=(const bigint &a, const bigint &b)
{
    if (a == b)
        return false;
    return true;
}

bool operator<(const bigint &a, const bigint &b)
{
    int cmp = compare_string(a.get_value(), b.get_value());
    if (cmp < 0)
        return true;
    return false;
}

bool operator<=(const bigint &a, const bigint &b)
{
    int cmp = compare_string(a.get_value(), b.get_value());
    if (cmp <= 0)
        return true;
    return false;
}

bool operator>(const bigint &a, const bigint &b)
{
    int cmp = compare_string(a.get_value(), b.get_value());
    if (cmp > 0)
        return true;
    return false;
}

bool operator>=(const bigint &a, const bigint &b)
{
    int cmp = compare_string(a.get_value(), b.get_value());
    if (cmp >= 0)
        return true;
    return false;
}

bigint operator+(const bigint &a, const bigint &b)
{
    const std::string &A = a.get_value();
    const std::string &B = b.get_value();

    std::string result;

    int i = (int)A.size() - 1;
    int j = (int)B.size() - 1;
    int carry = 0;

    while (i >= 0 || j >= 0 || carry > 0)
    {
        int digitA = 0;
        if (i >= 0)
            digitA = A[i] - '0';

        int digitB = 0;
        if (j >= 0)
            digitB = B[j] - '0';

        int sum = digitA + digitB + carry;
        int out_digit = sum % 10;
        carry = sum / 10;

        result.push_back(char('0' + out_digit));

        i--;
        j--;
    }
    std::reverse(result.begin(), result.end());

    return bigint(result);
}

bigint &bigint::operator=(const bigint &other)
{
    if (this != &other)
    {
        m_value = other.m_value;
    }
    return *this;
}

bigint &bigint::operator+=(const bigint &other)
{
    *this = *this + other;
    return *this;
}

bigint operator<<(const bigint &num, int k)
{
    std::string result = num.get_value();

    if (k <= 0)
        return num;

    if (result == "0")
        return num;

    result.append(k, '0');
    return bigint(result);
}

bigint operator>>(const bigint &num, int k)
{
    std::string result = num.get_value();

    if (k <= 0)
        return num;

    int size = result.size();
    if (k >= size)
        return (bigint("0"));

    result.erase(size - k);

    return (bigint(result));
}

bigint &bigint::operator<<=(int k)
{
    *this = *this << k;
    return *this;
}

bigint &bigint::operator>>=(int k)
{
    *this = *this >> k;
    return *this;
}
