#include "bigint.hpp"

bigint::bigint() : _val("0") {}

bigint::bigint(unsigned int i)
{
    std::ostringstream oss;
    oss << i;
    _val = oss.str();
    std::reverse(_val.begin(), _val.end());
}

bigint::bigint(const std::string &val)
{
    bool isDigi = true;
    for (std::string::const_iterator it = val.begin(); it < val.end(); ++it)
        if (!::isdigit(*it))
            isDigi = false;
    if (val.empty() || isDigi == false)
        _val = "0";
    else
    {
        _val = val;
        std::reverse(_val.begin(), _val.end());
        removeZero();
    }
}
bigint::bigint(const bigint &other) : _val(other._val) {}

bigint &bigint::operator=(const bigint &rhs)
{
    if (this != &rhs)
    {
        _val = rhs._val;
    }
    return *this;
}

bigint::~bigint() {}




void bigint::removeZero()
{
    while (_val.size() && _val[_val.size() - 1] == '0')
        _val.erase(_val.size() - 1);
}

std::string bigint::addStrings(const std::string s1, const std::string s2)
{
    std::string final;
    size_t result = 0, rest = 0, len = 0;
    len = (s1.size() > s2.size()) ? s1.size() : s2.size();
    for (size_t i = 0; i < len; i++)
    {
        int s1_r = (i < s1.size()) ? s1[i] - '0' : 0;
        int s2_r = (i < s2.size()) ? s2[i] - '0' : 0;
        result = s1_r + s2_r + rest;
        final.push_back((result % 10) + '0');
        rest = result / 10;
    }
    if (rest)
        final.push_back(rest + '0');
    return final;
}

bigint bigint::operator+(const bigint &bi)
{
    bigint res(addStrings(_val, bi._val));
    return res;
}

bigint &bigint::operator+=(const bigint &bi)
{
    _val = addStrings(_val, bi._val);
    return *this;
}

bigint bigint::operator++(int)
{
    bigint res(*this);
    _val = addStrings(_val, "1");
    return res;
}

bigint &bigint::operator++()
{
    _val = addStrings(_val, "1");
    return *this;
}

bool bigint::operator==(const bigint &bi) const
{
    if (this->_val == bi._val)
        return true;
    return false;
}
bool bigint::operator!=(const bigint &bi) const
{
    if (this->_val != bi._val)
        return true;
    return false;
}
bool bigint::operator<(const bigint &bi) const
{
    if (_val.size() < bi._val.size())
        return true;
    else if (_val.size() > bi._val.size())
        return false;
    else
    {
        for (size_t i = _val.size() - 1; i > _val.size(); i--)
        {
            if (_val[i] < bi._val[i])
                return true;
            else if (_val[i] > bi._val[i])
                return false;
            else
                continue;
        }
    }
    return false;
}

bool bigint::operator>(const bigint &bi) const
{
    if (_val.size() > bi._val.size())
        return true;
    else if (_val.size() < bi._val.size())
        return false;
    else
    {
        for (size_t i = _val.size() - 1; i > _val.size(); i--)
        {
            if (_val[i] > bi._val[i])
                return true;
            else if (_val[i] < bi._val[i])
                return false;
            else
                continue;
        }
    }
    return false;
}
bool bigint::operator>=(const bigint &bi) const
{
    if (_val.size() > bi._val.size() || _val == bi._val)
        return true;
    else if (_val.size() < bi._val.size())
        return false;
    else
    {
        for (size_t i = _val.size() - 1; i > _val.size(); i--)
        {
            if (_val[i] > bi._val[i])
                return true;
            else if (_val[i] < bi._val[i])
                return false;
            else
                continue;
        }
    }
    return false;
}
bool bigint::operator<=(const bigint &bi) const
{
    if (_val.size() < bi._val.size() || _val == bi._val)
        return true;
    else if (_val.size() > bi._val.size())
        return false;
    else
    {
        for (size_t i = _val.size() - 1; i > _val.size(); i--)
        {
            if (_val[i] < bi._val[i])
                return true;
            else if (_val[i] > bi._val[i])
                return false;
            else
                continue;
        }
    }
    return false;
}

bigint bigint::operator<<(unsigned int y) const
{
    std::string res = _val;
    std::reverse(res.begin(), res.end());
    for (size_t i = 0; i < y; i++)
        res.append("0");
    bigint result(res);
    return result;
}

bigint bigint::operator>>(unsigned int y) const
{
    std::string res = _val;
    std::reverse(res.begin(), res.end());
    for (size_t i = 0; i < y && !res.empty(); i++)
        res.erase(res.size() - 1);
    bigint result(res);
    return result;
}

bigint bigint::operator<<(const bigint &bi) const
{
    size_t dix = 1;
    std::string res = _val;
    std::reverse(res.begin(), res.end());
    for (size_t i = 0; i < bi._val.size(); i++)
    {
        for (size_t y = 0; y < (size_t)((bi._val[i] - '0') * dix); y++)
            res.append("0");
        dix *= 10;
    }
    bigint result(res);
    return result;
}

bigint bigint::operator>>(const bigint &bi) const
{
    size_t dix = 1;
    std::string res = _val;
    std::reverse(res.begin(), res.end());
    for (size_t i = 0; i < bi._val.size(); i++)
    {
        if (res.empty())
            break;
        for (size_t y = 0; y < (size_t)((bi._val[i] - '0') * dix); y++)
        {
            res.erase(res.size() - 1);
            if (res.empty())
                break;
        }
        dix *= 10;
    }
    bigint result(res);
    return result;
}

bigint &bigint::operator<<=(unsigned int y)
{
    *this = *this << y;
    return *this;
}
bigint &bigint::operator>>=(unsigned int y)
{
    *this = *this >> y;
    return *this;
}

bigint &bigint::operator<<=(const bigint &bi)
{
    *this = *this << bi;
    return *this;
}
bigint &bigint::operator>>=(const bigint &bi)
{
    *this = *this >> bi;
    return *this;
}

void bigint::print(std::ostream &os) const
{
    std::string res = _val;
    std::reverse(res.begin(), res.end());
    os << res << std::endl;
}

std::ostream &operator<<(std::ostream &os, const bigint &bi)
{
    bi.print(os);
    return os;
}