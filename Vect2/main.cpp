#include "vect2.hpp"

int main()
{
    std::cout << "[Final integration test]\n";

    // --- Construction + printing ---
    vect2 v1;           // {0,0}
    vect2 v2(1, 2);     // {1,2}
    const vect2 v3(v2); // {1,2}
    vect2 v4 = v2;      // {1,2}
    std::cout << "v1           actual: " << v1 << " | expected: {0, 0}\n";
    std::cout << "v2           actual: " << v2 << " | expected: {1, 2}\n";
    std::cout << "v3 (const)   actual: " << v3 << " | expected: {1, 2}\n";
    std::cout << "v4           actual: " << v4 << " | expected: {1, 2}\n";

    // --- operator[] (write + read + const read) ---
    v1[0] = 10;
    v1[1] = 20;
    std::cout << "v1 after []  actual: " << v1 << " | expected: {10, 20}\n";
    int r0 = v1[0], r1 = v1[1];
    std::cout << "reads v1[]   actual: [" << r0 << ", " << r1 << "] | expected: [10, 20]\n";
    int cr0 = v3[0], cr1 = v3[1]; // const read
    std::cout << "reads v3[]   actual: [" << cr0 << ", " << cr1 << "] | expected: [1, 2]\n";

    // --- Binary +, -, * (both orders) ---
    vect2 a(1, 2), b(3, 4);
    vect2 sum = a + b;       // {4,6}
    vect2 diff = a - b;      // {-2,-2}
    vect2 mulL = a * 3;      // {3,6}
    vect2 mulR = 4 * b;      // {12,16}
    vect2 chain = a + b * 2; // {1,2}+{6,8} = {7,10}
    std::cout << "a + b        actual: " << sum << " | expected: {4, 6}\n";
    std::cout << "a - b        actual: " << diff << " | expected: {-2, -2}\n";
    std::cout << "a * 3        actual: " << mulL << " | expected: {3, 6}\n";
    std::cout << "4 * b        actual: " << mulR << " | expected: {12, 16}\n";
    std::cout << "a + b*2      actual: " << chain << " | expected: {7, 10}\n";

    // --- Compound ops (+=, -=, *=) including chaining ---
    vect2 c(5, 6), d(1, 2);
    c += d; // {6,8}
    std::cout << "c += d        actual: " << c << " | expected: {6, 8}\n";
    c -= vect2(2, 3); // {4,5}
    std::cout << "c -= {2,3}    actual: " << c << " | expected: {4, 5}\n";
    c *= -2; // {-8,-10}
    std::cout << "c *= -2       actual: " << c << " | expected: {-8, -10}\n";

    // Chaining: v2 += v2 += v3  (well-defined: inner completes before outer)
    vect2 cc(1, 2); // a_old = {1,2}
    vect2 vv(10, 1);
    cc += (cc += vv); // inner: cc = {11,3}; outer: cc = {22,6}
    std::cout << "cc chain     actual: " << cc << " | expected: {22, 6}\n";

    // --- Unary + and - ---
    vect2 u(3, -4);
    std::cout << "+u           actual: " << (+u) << " | expected: {3, -4}\n";
    std::cout << "-u           actual: " << (-u) << " | expected: {-3, 4}\n";

    // --- ++ / -- (prefix & postfix) with standard semantics ---
    vect2 inc(1, 2);

    vect2 post1 = inc++; // returns old {1,2}, inc -> {2,3}
    std::cout << "post1=v++     actual: " << post1 << " | expected: {1, 2}\n";
    std::cout << "inc after++   actual: " << inc << " | expected: {2, 3}\n";

    vect2 &pre1 = ++inc; // inc -> {3,4}, pre1 aliases inc
    std::cout << "++inc result  actual: " << pre1 << " | expected: {3, 4}\n";
    std::cout << "inc after++   actual: " << inc << " | expected: {3, 4}\n";

    vect2 post2 = inc--; // returns old {3,4}, inc -> {2,3}
    std::cout << "post2=v--     actual: " << post2 << " | expected: {3, 4}\n";
    std::cout << "inc after--   actual: " << inc << " | expected: {2, 3}\n";

    vect2 &pre2 = --inc; // inc -> {1,2}
    std::cout << "--inc result  actual: " << pre2 << " | expected: {1, 2}\n";
    std::cout << "inc final     actual: " << inc << " | expected: {1, 2}\n";

    // --- Comparisons ---
    std::cout << "v2 == v3      actual: " << (v2 == v3) << " | expected: 1\n";
    std::cout << "v2 != v3      actual: " << (v2 != v3) << " | expected: 0\n";
    std::cout << "v1 == v2      actual: " << (v1 == v2) << " | expected: 0\n";
    std::cout << "v1 != v2      actual: " << (v1 != v2) << " | expected: 1\n";

    // --- Final small sanity ---
    vect2 z(0, 0);
    ++z;
    z++;
    --z;
    z--; // back to {0,0}
    std::cout << "z roundtrip   actual: " << z << " | expected: {0, 0}\n";

    return 0;
}
