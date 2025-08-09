#include "BigInt.hpp"
#include <iostream>

int main()
{
    bigint a;                 // should be 0
    bigint b(42);             // should be 42
    bigint c("000012345600"); // should be 12345600
    bigint d("458xa");        // should be 0

    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "c: " << c << std::endl;
    std::cout << "d: " << d << std::endl;


    return 0;
}
