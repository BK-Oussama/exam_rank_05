#include "vect2.hpp"

vect2::vect2(){
	p.first = 0;
	p.second = 0;
}

vect2::vect2(int nb, int onb){
	p.first = nb;
	p.second = onb;
}

vect2::vect2(const vect2& other){
	p.first = other.p.first;
	p.second = other.p.second;
}

vect2& vect2::operator=(const vect2& other){
	if (this != &other)
	{
		p.first = other.p.first;
		p.second = other.p.second;
	}
	return (*this);
}

int vect2::operator[](int nb) const{
	if (!nb)
		return p.first;
	else if (nb == 1)
		return p.second;
	return (cerr << "invalid index"<< endl, -1);
}

int& vect2::operator[](int nb){
	if (!nb)
		return p.first;
	return p.second;
}

vect2&	vect2::operator++(){
	p.first++;
	p.second++;
	return (*this);
}

vect2 	vect2::operator++(int){
	vect2 tmp(*this);
	tmp.p.first++;
	tmp.p.second++;
	return (tmp);
}

vect2& 	vect2::operator--(){
	p.first--;
	p.second--;
	return (*this);
}

vect2 	vect2::operator--(int){
	vect2 tmp(*this);
	tmp.p.first--;
	tmp.p.second--;
	return (tmp);
}


vect2& 	vect2::operator+=(const vect2& other){
	p.first += other.p.first;
	p.second += other.p.second;
	return (*this);

}

vect2 	vect2::operator+(const vect2& other) const{
	vect2 tmp(*this);
	tmp.p.first += other.p.first;
	tmp.p.second += other.p.second;
	return (tmp);
}

vect2& 	vect2::operator-=(const vect2& other){
	p.first -= other.p.first;
	p.second -= other.p.second;
	return (*this);
}

vect2 	vect2::operator-(const vect2& other) const{
	vect2 tmp(*this);
	tmp.p.first -= other.p.first;
	tmp.p.second -= other.p.second;
	return (tmp);
}

vect2  	vect2::operator*(int nb) const{
	vect2 tmp(*this);
	tmp *= nb;
	return (tmp);
}

vect2& 	vect2::operator*=(int nb){
	p.first *= nb;
	p.second *= nb;
	return (*this);
}

vect2 	vect2::operator-() const{
	vect2 tmp(*this);
	tmp.p.first  = -tmp.p.first;
	tmp.p.second = -tmp.p.second;
	return (tmp);
	
}

bool	vect2::operator==(const vect2& other){
	return (p.first == other.p.first && p.second == other.p.second);
}

bool	vect2::operator!=(const vect2& other){
	return !(p.first == other.p.first && p.second == other.p.second);
}


ostream& operator<<(ostream& out, const vect2& vec){
	return (out << "{" << vec[0] << ", " << vec[1] << "}");
}

vect2 operator*(int nb, const vect2& vec){
	vect2 tmp(vec);
	tmp *= nb;
	return(tmp);
}
