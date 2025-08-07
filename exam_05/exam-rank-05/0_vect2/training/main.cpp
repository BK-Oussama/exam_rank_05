#include "vect2.hpp"
#include <iostream>

int main() {
	vect2 v1;                    // default: {0, 0}
	vect2 v2(1, 2);              // init: {1, 2}
	const vect2 v3(v2);         // copy constructor: {1, 2}
	vect2 v4 = v2;              // copy assignment: {1, 2}

	std::cout << "v1: " << v1 << std::endl;
	std::cout << "v1: {" << v1[0] << ", " << v1[1] << "}" << std::endl;

	std::cout << "v2: " << v2 << std::endl;
	std::cout << "v3: " << v3 << std::endl;
	std::cout << "v4: " << v4 << std::endl;

	std::cout << "v4++: " << v4++ << std::endl; // should print before increment
	std::cout << "v4 after post++: " << v4 << std::endl;
	std::cout << "++v4: " << ++v4 << std::endl;
	std::cout << "v4--: " << v4-- << std::endl;
	std::cout << "--v4: " << --v4 << std::endl;

	v2 += v3;                  // v2 = {2, 4}
	std::cout << "v2 += v3: " << v2 << std::endl;

	v1 -= v2;                  // v1 = {-2, -4}
	std::cout << "v1 -= v2: " << v1 << std::endl;

	v2 = v3 + v3 * 2;          // v2 = {1,2} + {2,4} = {3,6}
	std::cout << "v2 = v3 + v3 * 2: " << v2 << std::endl;

	v2 = 3 * v2;               // v2 = {9, 18}
	std::cout << "v2 = 3 * v2: " << v2 << std::endl;

	v2 += v2 += v3;            // v2 = (v2 += v3), then += again
	std::cout << "v2 += v2 += v3: " << v2 << std::endl;

	v1 *= 42;                  // v1 = {-84, -168}
	std::cout << "v1 *= 42: " << v1 << std::endl;

	v1 = v1 - v1 + v1;         // v1 = {0,0} + {-84,-168} = {-84,-168}
	std::cout << "v1 = v1 - v1 + v1: " << v1 << std::endl;

	std::cout << "-v2: " << -v2 << std::endl;

	std::cout << "v1[1]: " << v1[1] << std::endl;
	v1[1] = 12;
	std::cout << "v1[1] after set: " << v1[1] << std::endl;

	std::cout << "v3[1]: " << v3[1] << std::endl;

	std::cout << "v1 == v3: " << (v1 == v3) << std::endl;
	std::cout << "v1 == v1: " << (v1 == v1) << std::endl;
	std::cout << "v1 != v3: " << (v1 != v3) << std::endl;
	std::cout << "v1 != v1: " << (v1 != v1) << std::endl;

	return 0;
}
