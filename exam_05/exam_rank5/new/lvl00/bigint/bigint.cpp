#include "bigint.hpp"

bigint::bigint(){
    big.push_back(0);
}

bigint::bigint(const bigint&other){
    big = other.big;

    while (big.size() > 1 && big.back() == 0)
        big.pop_back();
}

bigint::bigint(unsigned long long nb){
    if (nb == 0)
        big.push_back(0);
    while (nb)
    {
        big.push_back(nb % 10);
        nb /= 10;
    }
}

bigint::~bigint(){}

string bigint::getBig() const{
    string str, nstr;
    bigV::const_reverse_iterator rit;
    
    for (rit = big.rbegin(); rit != big.rend(); rit++ )
        str += *rit + '0';
    
    string::iterator it = str.begin();
    if (str.size() > 1 && *it == '0')
    {
        for (;*it == '0'; it++)
            ;
        for (; it != str.end(); it++)
            nstr += *it ;    
    }
    else
        nstr = str;
    return nstr;
}

bigint& bigint::operator+=(const bigint& other){
    size_t max = (big.size() > other.big.size() ? big.size() : other.big.size());
    int extra = 0;
    bigV tmp;

    for (size_t i = 0 ; i < max ; i++ ){
        int a = i < big.size() ? big[i] : 0;
        int b = i < other.big.size() ? other.big[i] : 0;
        int sum = a + b + extra;
        sum > 9 ? (sum -= 10 , extra = 1) : extra = 0;
        tmp.push_back(sum);
    }
    if (extra)
        tmp.push_back(extra);
    big = tmp;
    return *this;
}

bigint 	bigint::operator+(const bigint& other)const{
    bigint tmp(*this);
    tmp += other;
    return tmp;
}

bigint& bigint::operator++(){
    *this += 1;
    return *this;
}

bigint bigint::operator++(int){
    bigint tmp(*this);
     *this += 1;
    return tmp;
}

bigint 	bigint::operator<<(unsigned int nb)const{
    bigint tmp(*this);
    for( ; nb ;nb--)
        tmp.big.insert(tmp.big.begin(), 0);
    return tmp;
}

bigint& bigint::operator>>=(const bigint & other){
    int nb = 0;

    bigV::const_reverse_iterator rit = other.big.rbegin();
    for (; rit != other.big.rend(); rit++)
    {
        nb *= 10;
        nb += *rit;
    }
    big.erase(big.begin(),big.begin() + nb);
    return *this;
}

bigint& bigint::operator<<=(unsigned int nb){
    for( ; nb ;nb--)
        big.insert(big.begin(), 0);
    return *this;
}

bool 	bigint::operator>(const bigint&other)const{
    if (big.size() > other.big.size())
        return true;
    if (big.size() < other.big.size())
        return false;

    for (int i =  big.size() - 1; i >= 0 ; i--)
        if (big[i] != other.big[i])
            return (big[i] > other.big[i]);
    return false;
}

bool 	bigint::operator<(const bigint&other)const{
    return other > *this;
}

bool 	bigint::operator==(const bigint&other)const{
    return big == other.big;
}

bool 	bigint::operator!=(const bigint&other)const{
    return !(big == other.big);
}

bool bigint::operator<=(const bigint& other) const {
    return !(*this > other);
}

bool bigint::operator>=(const bigint& other) const {
    return !(*this < other);
}

ostream & operator<<(ostream& out, const bigint &big){
    return (out << big.getBig()); 
}