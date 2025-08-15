#include "bigint.hpp"


// int main()
// {
//     // bigint a;                 // should be 0
//     // bigint b(42);             // should be 42
//     // bigint c("000012345600"); // should be 12345600

//     // std::cout << "a: " << a << std::endl;
//     // std::cout << "b: " << b << std::endl;
//     // std::cout << "c: " << c << std::endl;
//     // std::cout << "d: " << d << std::endl;


//         bigint a("0"), b("00"), c("9"), d("4294967295"), e("100"), f("4294967295"), g("1000");
//     // assuming your ctor/trim normalize inputs
//     // assert(a == b);
//     // assert(c < d);
//     // assert(e < g);
//     // assert(g > e);
//     // assert(d <= d);
//     // assert(e >= d);

//     std::cout << "a: " << a << std::endl;
//     std::cout << "d: " << d << std::endl;
//     std::cout << "f: " << f << std::endl;
//     // std::cout << "f + d: " << (d + f) << std::endl;
//     std::cout << "c + e: " << (c += e) << std::endl;

//     return 0;
// }



// int main()
// {
//     bigint a("42");

//     // 1. Left shift by 0 (no change)
//     std::cout << "1: " << (a << 0) << "\n";

//     // 2. Left shift by positive k
//     std::cout << "2: " << (a << 3) << "\n"; // 42000

//     // 3. Left shift on "0"
//     bigint b("0");
//     std::cout << "3: " << (b << 5) << "\n"; // 0

//     // 4. Right shift by 0 (no change)
//     std::cout << "4: " << (a >> 0) << "\n"; // 42

//     // 5. Right shift by 1
//     std::cout << "5: " << (a >> 1) << "\n"; // 4

//     // 6. Right shift by len-1
//     std::cout << "6: " << (a >> 1) << "\n"; // 4

//     // 7. Right shift by len (becomes 0)
//     std::cout << "7: " << (a >> 2) << "\n"; // 0

//     // 8. Right shift by > len
//     std::cout << "8: " << (a >> 5) << "\n"; // 0

//     // 9. Large number left shift
//     bigint c("123456789");
//     std::cout << "9: " << (c << 2) << "\n"; // 12345678900

//     // 10. Large number right shift partially
//     std::cout << "10: " << (c >> 4) << "\n"; // 12345

//     return 0;
// }


#include <iostream>

int main()
{
    // Left-shift chaining (explicit left grouping)
    bigint k("5");
    (k <<= 2) <<= 2;     // k = (((k <<= 2)) <<= 2) -> 5 -> 500 -> 50000
    std::cout << "k: " << k << " (Expected: 50000)\n";

    // Right-shift chaining (explicit left grouping)
    bigint l("987654");
    (l >>= 2) >>= 2;     // 987654 -> 9876 -> 98
    std::cout << "l: " << l << " (Expected: 98)\n";

    // Mixed chaining (explicit left grouping)
    bigint m("12345");
    (m <<= 3) >>= 4;     // 12345 -> 12345000 -> 1234
    std::cout << "m: " << m << " (Expected: 1234)\n";

    return 0;
}
