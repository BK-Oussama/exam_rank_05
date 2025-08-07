// #include "bigint.hpp"
// #include <iostream>

// int main() {
// 	bigint a(42);
// 	bigint b(21), c, d(1337), e(d);
// 	bigint big(1);

// 	std::cout << "(big << 18) = " << (big << 18) << "\n\n";

// 	std::cout << "a = " << a << "\n";
// 	std::cout << "b = " << b << "\n";
// 	std::cout << "c = " << c << "\n";
// 	std::cout << "d = " << d << "\n";
// 	std::cout << "e = " << e << "\n\n";

// 	std::cout << "a + b = " << (a + b) << "\n";
// 	std::cout << "(c += a) = " << (c += a) << "\n\n";

// 	std::cout << "b = " << b << "\n";
// 	std::cout << "++b = " << ++b << "\n";
// 	std::cout << "b++ = " << b++ << "\n";
// 	std::cout << "b (after b++) = " << b << "\n\n";

// 	std::cout << "(b << 10) + 42 = " << ((b << 10) + 42) << "\n";
// 	std::cout << "(d <<= 4) = " << (d <<= 4) << "\n";
// 	std::cout << "(d >>= 2) = " << (d >>= 2) << "\n\n";

// 	std::cout << "a = " << a << "\n";
// 	std::cout << "d = " << d << "\n";
// 	std::cout << "(d < a) = " << (d < a) << "\n";
// 	std::cout << "(d <= a) = " << (d <= a) << "\n";
// 	std::cout << "(d > a) = " << (d > a) << "\n";
// 	std::cout << "(d >= a) = " << (d >= a) << "\n";
// 	std::cout << "(d == a) = " << (d == a) << "\n";
// 	std::cout << "(d != a) = " << (d != a) << "\n\n";

// 	bigint x(1234);
// 	std::cout << "(x << 2) = " << (x << 2) << "\n";
// 	std::cout << "(x >>= 2) = " << (x >>= 2) << "\n\n";

// 	std::cout << "--- Extra Tests ---\n";

// 	bigint m(12345), n(12345);
// 	std::cout << "m = " << m << ", n = " << n << "\n";
// 	std::cout << "m - n = " << (m - n) << " (dummy)\n\n";

// 	bigint shift1(123456789);
// 	std::cout << "shift1 >> 3 = " << (shift1 >> 3) << "\n";
// 	shift1 >>= 3;
// 	std::cout << "shift1 after >>= 3 = " << shift1 << "\n\n";

// 	bigint huge(1);
// 	std::cout << "(1 << 10) = " << (huge << 10) << "\n";
// 	std::cout << "(1 << 18) = " << (huge << 18) << "\n\n";

// 	bigint a1(1000), a2(999);
// 	std::cout << "a1 = " << a1 << ", a2 = " << a2 << "\n";
// 	std::cout << "a1 > a2: " << (a1 > a2) << "\n";
// 	std::cout << "a1 == a2: " << (a1 == a2) << "\n";
// 	std::cout << "a1 - a2 (dummy): " << (a1 - a2) << "\n\n";

// 	bigint z1(0), z2(0);
// 	std::cout << "0 - 0 = " << (z1 - z2) << "\n";

// 	std::cout << "a1 >= a2: " << (a1 >= a2) << "\n";
// 	std::cout << "a2 <= a1: " << (a2 <= a1) << "\n";
// 	std::cout << "a2 < a1: " << (a2 < a1) << "\n";
// 	std::cout << "a2 != a1: " << (a2 != a1) << "\n";

// 	return 0;
// }


// --------------------------------------------------------------------------------

#include "bigint.hpp"
#include <iostream>
#include <cassert>

void test_constructors() {
	std::cout << "=== TEST CONSTRUCTORS ===" << std::endl;
	
	// Test default constructor
	bigint zero;
	std::cout << "Default constructor: " << zero << std::endl;
	
	// Test constructor from unsigned int
	bigint a(0);
	bigint b(42);
	bigint c(1337);
	bigint d(999999);
	
	std::cout << "bigint(0): " << a << std::endl;
	std::cout << "bigint(42): " << b << std::endl;
	std::cout << "bigint(1337): " << c << std::endl;
	std::cout << "bigint(999999): " << d << std::endl;
	
	// Test copy constructor
	bigint e(c);
	std::cout << "Copy of 1337: " << e << std::endl;
	
	std::cout << std::endl;
}

void test_assignment() {
	std::cout << "=== TEST ASSIGNMENT ===" << std::endl;
	
	bigint a(42);
	bigint b(21);
	bigint c;
	
	c = a;
	std::cout << "c = a (42): " << c << std::endl;
	
	// Test self-assignment
	a = a;
	std::cout << "Self assignment a = a: " << a << std::endl;
	
	// Chain assignment
	bigint d, e;
	d = e = b;
	std::cout << "Chain assignment d = e = b: d=" << d << ", e=" << e << std::endl;
	
	std::cout << std::endl;
}

void test_addition() {
	std::cout << "=== TEST ADDITION ===" << std::endl;
	
	bigint a(42);
	bigint b(21);
	bigint zero(0);
	
	std::cout << "42 + 21 = " << (a + b) << std::endl;
	std::cout << "42 + 0 = " << (a + zero) << std::endl;
	std::cout << "0 + 42 = " << (zero + a) << std::endl;
	
	// Test with numbers that generate carry
	bigint x(999);
	bigint y(1);
	std::cout << "999 + 1 = " << (x + y) << std::endl;
	
	// Test +=
	bigint c(10);
	std::cout << "c = " << c << std::endl;
	c += bigint(5);
	std::cout << "c += 5: " << c << std::endl;
	
	std::cout << std::endl;
}

void test_increment() {
	std::cout << "=== TEST INCREMENT ===" << std::endl;
	
	bigint a(42);
	std::cout << "a = " << a << std::endl;
	std::cout << "++a = " << ++a << std::endl;
	std::cout << "a after ++a = " << a << std::endl;
	
	bigint b(99);
	std::cout << "b = " << b << std::endl;
	std::cout << "b++ = " << b++ << std::endl;
	std::cout << "b after b++ = " << b << std::endl;
	
	// Test with zero
	bigint zero(0);
	std::cout << "zero = " << zero << std::endl;
	std::cout << "++zero = " << ++zero << std::endl;
	
	std::cout << std::endl;
}

void test_shift_operations() {
	std::cout << "=== TEST SHIFT OPERATIONS ===" << std::endl;
	
	bigint a(42);
	bigint zero(0);
	bigint one(1);
	
	// Test left shift
	std::cout << "42 << 0 = " << (a << 0) << std::endl;
	std::cout << "42 << 1 = " << (a << 1) << std::endl;
	std::cout << "42 << 3 = " << (a << 3) << std::endl;
	std::cout << "0 << 5 = " << (zero << 5) << std::endl;
	std::cout << "1 << 10 = " << (one << 10) << std::endl;
	
	// Test right shift
	bigint big(123456);
	std::cout << "123456 >> 0 = " << (big >> 0) << std::endl;
	std::cout << "123456 >> 2 = " << (big >> 2) << std::endl;
	std::cout << "123456 >> 6 = " << (big >> 6) << std::endl;
	std::cout << "123456 >> 10 = " << (big >> 10) << std::endl;
	
	// Test <<= and >>=
	bigint c(1337);
	std::cout << "c = " << c << std::endl;
	c <<= 4;
	std::cout << "c <<= 4: " << c << std::endl;
	c >>= 2;
	std::cout << "c >>= 2: " << c << std::endl;
	
	std::cout << std::endl;
}

void test_comparison() {
	std::cout << "=== TEST COMPARISONS ===" << std::endl;
	
	bigint a(42);
	bigint b(42);
	bigint c(21);
	bigint d(100);
	bigint zero(0);
	
	// Test equality
	std::cout << "42 == 42: " << (a == b) << std::endl;
	std::cout << "42 == 21: " << (a == c) << std::endl;
	std::cout << "42 != 21: " << (a != c) << std::endl;
	std::cout << "0 == 0: " << (zero == bigint(0)) << std::endl;
	
	// Test ordering
	std::cout << "42 < 100: " << (a < d) << std::endl;
	std::cout << "100 < 42: " << (d < a) << std::endl;
	std::cout << "42 < 42: " << (a < b) << std::endl;
	
	std::cout << "42 > 21: " << (a > c) << std::endl;
	std::cout << "21 > 42: " << (c > a) << std::endl;
	
	std::cout << "42 <= 42: " << (a <= b) << std::endl;
	std::cout << "42 <= 100: " << (a <= d) << std::endl;
	std::cout << "100 <= 42: " << (d <= a) << std::endl;
	
	std::cout << "42 >= 42: " << (a >= b) << std::endl;
	std::cout << "100 >= 42: " << (d >= a) << std::endl;
	std::cout << "21 >= 42: " << (c >= a) << std::endl;
	
	// Test with numbers of different length
	bigint small(9);
	bigint large(10);
	std::cout << "9 < 10: " << (small < large) << std::endl;
	std::cout << "10 > 9: " << (large > small) << std::endl;
	
	bigint tiny(1);
	bigint huge(1000000);
	std::cout << "1 < 1000000: " << (tiny < huge) << std::endl;
	
	std::cout << std::endl;
}

void test_subtraction() {
	std::cout << "=== TEST SUBTRACTION (DUMMY) ===" << std::endl;
	
	bigint a(42);
	bigint b(21);
	bigint c(42);
	
	std::cout << "42 - 21 = " << (a - b) << " (dummy implementation)" << std::endl;
	std::cout << "42 - 42 = " << (a - c) << " (should be 0)" << std::endl;
	std::cout << "21 - 42 = " << (b - a) << " (dummy implementation)" << std::endl;
	
	std::cout << std::endl;
}

void test_edge_cases() {
	std::cout << "=== TEST EDGE CASES ===" << std::endl;
	
	// Test with zero
	bigint zero(0);
	bigint one(1);
	
	std::cout << "0 + 0 = " << (zero + zero) << std::endl;
	std::cout << "0 + 1 = " << (zero + one) << std::endl;
	std::cout << "0 << 5 = " << (zero << 5) << std::endl;
	std::cout << "0 >> 5 = " << (zero >> 5) << std::endl;
	
	// Test with large numbers
	bigint big1(999999999);
	bigint big2(1);
	std::cout << "999999999 + 1 = " << (big1 + big2) << std::endl;
	
	// Test extreme shifts
	bigint x(123);
	std::cout << "123 >> 100 = " << (x >> 100) << std::endl;
	
	std::cout << std::endl;
}

void test_complex_operations() {
	std::cout << "=== TEST COMPLEX OPERATIONS ===" << std::endl;
	
	// Combinations of operations
	bigint a(42);
	bigint b(21);
	
	std::cout << "(42 << 2) + 21 = " << ((a << 2) + b) << std::endl;
	std::cout << "(42 + 21) << 1 = " << ((a + b) << 1) << std::endl;
	
	bigint c(1000);
	c += bigint(337);
	c <<= 2;
	std::cout << "c = 1000, c += 337, c <<= 2: " << c << std::endl;
	
	// Test with multiple increments
	bigint counter(0);
	for(int i = 0; i < 5; i++) {
		std::cout << "counter++ = " << counter++ << std::endl;
	}
	std::cout << "Final counter = " << counter << std::endl;
	
	std::cout << std::endl;
}

int main() {
	std::cout << "STARTING COMPLETE TESTS FOR BIGINT\n" << std::endl;
	
	test_constructors();
	test_assignment();
	test_addition();
	test_increment();
	test_shift_operations();
	test_comparison();
	test_subtraction();
	test_edge_cases();
	test_complex_operations();
	
	std::cout << "END TESTS - If there are no crashes, most functionality works!" << std::endl;
	
	return 0;
}