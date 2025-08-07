#ifndef AF362267_6362_483A_AF07_185743BE0F6E
#define AF362267_6362_483A_AF07_185743BE0F6E
#ifndef VECT2_HPP
#define VECT2_HPP

#include <iostream>
#include <string>

class vect2 {
    private:
        int _x;
        int _y;

    public:
    vect2(int x = 0, int y = 0);
    vect2(const vect2& other);
    vect2& operator=(const vect2& rhs);
    ~vect2();

    
    int& operator[](int i);
    int operator[](int i) const;

    vect2 operator+(int i);
    vect2 operator*(int i);
    vect2 operator+(const vect2& vec);
    vect2 operator*(const vect2& vec);

    vect2 operator++(int);
    vect2& operator++();
    vect2 operator--(int);
    vect2& operator--();

    bool operator==(const vect2& vec);
    bool operator!=(const vect2& vec);

    vect2& operator+=(int i);
    vect2& operator-=(int i);
    vect2& operator+=(const vect2& vec);
    vect2& operator-=(const vect2& vec);

    void print(std::ostream& os) const;
    friend vect2 operator+(int i, const vect2& vect);
    friend vect2 operator*(int i, const vect2& vect);
    friend std::ostream& operator<<(std::ostream& os, const vect2& obj);
};



#endif


#endif /* AF362267_6362_483A_AF07_185743BE0F6E */
