
#include "BigInt.hpp"

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


}

static int compare_strings(const std::string &A, const std::string &B)
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
}